import sys
sys.path.append('/Users/kb/bin/opencv-3.1.0/build/lib/')

import cv2
import numpy as np

def cross_correlation_2d(img, kernel):
    '''Given a kernel of arbitrary m x n dimensions, with both m and n being
    odd, compute the cross correlation of the given image with the given
    kernel, such that the output is of the same dimensions as the image and that
    you assume the pixels out of the bounds of the image to be zero. Note that
    you need to apply the kernel to each channel separately, if the given image
    is an RGB image.

    Inputs:
        img:    Either an RGB image (height x width x 3) or a grayscale image
                (height x width) as a numpy array.
        kernel: A 2D numpy array (m x n), with m and n both odd (but may not be
                equal).

    Output:
        Return an image of the same dimensions as the input image (same width,
        height and the number of color channels)
    '''
    # TODO-BLOCK-BEGIN
    height = img.shape[0]
    weight = img.shape[1]
    m = kernel.shape[0]
    n = kernel.shape[1]
    if len(img.shape) == 3:
        dimension = 3
        output = np.zeros((height, weight, dimension))
        padding = np.zeros((height + 2 * (m // 2), weight + 2 * (n // 2), dimension))
        padding[m // 2: - (m // 2), n // 2: - (n // 2)] = img
        for k in range(0, dimension):
            for i in range(0, height):
                for j in range(0, weight):
                    output[i, j, k] = np.vdot(padding[i: i + m, j: j + n, k], kernel)
        return output.reshape(img.shape)
    else:
        dimension = 1
        output = np.zeros((height, weight))
        padding = np.zeros((height + 2 * (m // 2), weight + 2 * (n // 2)))
        padding[m // 2: - (m // 2), n // 2: - (n // 2)] = img
        for k in range(0, dimension):
            for i in range(0, height):
                for j in range(0, weight):
                    output[i, j] = np.vdot(padding[i: i + m, j: j + n], kernel)
        return output.reshape(img.shape)

    # raise Exception("TODO in hybrid.py not implemented")
    # TODO-BLOCK-END

def convolve_2d(img, kernel):
    '''Use cross_correlation_2d() to carry out a 2D convolution.

    Inputs:
        img:    Either an RGB image (height x width x 3) or a grayscale image
                (height x width) as a numpy array.
        kernel: A 2D numpy array (m x n), with m and n both odd (but may not be
                equal).

    Output:
        Return an image of the same dimensions as the input image (same width,
        height and the number of color channels)
    '''
    # TODO-BLOCK-BEGIN
    kernel90 = np.rot90(kernel)
    kernel180 = np.rot90(kernel90)
    return cross_correlation_2d(img, kernel180)
    # raise Exception("TODO in hybrid.py not implemented")
    # TODO-BLOCK-END

def gaussian_blur_kernel_2d(sigma, height, width):
    '''Return a Gaussian blur kernel of the given dimensions and with the given
    sigma. Note that width and height are different.

    Input:
        sigma:  The parameter that controls the radius of the Gaussian blur.
                Note that, in our case, it is a circular Gaussian (symmetric
                across height and width).
        width:  The width of the kernel.
        height: The height of the kernel.

    Output:
        Return a kernel of dimensions height x width such that convolving it
        with an image results in a Gaussian-blurred image.
    '''
    # TODO-BLOCK-BEGIN
    gaussian = np.zeros((height, width))
    sum = 0
    for x in range(0, height):
        for y in range(0, width):
            gaussian[x, y] = 1 / (2 * np.pi * sigma * sigma) * np.exp(
                -((x - height // 2) * (x - height // 2) + (y - width // 2) * (y - width // 2)) / (2 * sigma * sigma))
            sum = sum + gaussian[x, y]
    return gaussian / sum
    # raise Exception("TODO in hybrid.py not implemented")
    # TODO-BLOCK-END

def low_pass(img, sigma, size):
    '''Filter the image as if its filtered with a low pass filter of the given
    sigma and a square kernel of the given size. A low pass filter supresses
    the higher frequency components (finer details) of the image.

    Output:
        Return an image of the same dimensions as the input image (same width,
        height and the number of color channels)
    '''
    # TODO-BLOCK-BEGIN
    return convolve_2d(img, gaussian_blur_kernel_2d(sigma, size, size))
    # raise Exception("TODO in hybrid.py not implemented")
    # TODO-BLOCK-END

def high_pass(img, sigma, size):
    '''Filter the image as if its filtered with a high pass filter of the given
    sigma and a square kernel of the given size. A high pass filter suppresses
    the lower frequency components (coarse details) of the image.

    Output:
        Return an image of the same dimensions as the input image (same width,
        height and the number of color channels)
    '''
    # TODO-BLOCK-BEGIN
    return img - low_pass(img, sigma, size)
    # raise Exception("TODO in hybrid.py not implemented")
    # TODO-BLOCK-END

def create_hybrid_image(img1, img2, sigma1, size1, high_low1, sigma2, size2,
        high_low2, mixin_ratio):
    '''This function adds two images to create a hybrid image, based on
    parameters specified by the user.'''
    high_low1 = high_low1.lower()
    high_low2 = high_low2.lower()

    if img1.dtype == np.uint8:
        img1 = img1.astype(np.float32) / 255.0
        img2 = img2.astype(np.float32) / 255.0

    if high_low1 == 'low':
        img1 = low_pass(img1, sigma1, size1)
    else:
        img1 = high_pass(img1, sigma1, size1)

    if high_low2 == 'low':
        img2 = low_pass(img2, sigma2, size2)
    else:
        img2 = high_pass(img2, sigma2, size2)

    img1 *= 2 * (1 - mixin_ratio)
    img2 *= 2 * mixin_ratio
    hybrid_img = (img1 + img2)
    return (hybrid_img * 255).clip(0, 255).astype(np.uint8)


