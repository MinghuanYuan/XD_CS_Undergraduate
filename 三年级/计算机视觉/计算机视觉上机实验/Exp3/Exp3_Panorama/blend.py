import math
import sys

import cv2
import numpy as np


class ImageInfo:
    def __init__(self, name, img, position):
        self.name = name
        self.img = img
        self.position = position


def imageBoundingBox(img, M):
    """
       This is a useful helper function that you might choose to implement
       that takes an image, and a transform, and computes the bounding box
       of the transformed image.

       INPUT:
         img: image to get the bounding box of
         M: the transformation to apply to the img
       OUTPUT:
         minX: int for the minimum X value of a corner
         minY: int for the minimum Y value of a corner
         maxX: int for the maximum X value of a corner
         maxY: int for the maximum Y value of a corner
    """
    # TODO 8
    # TODO-BLOCK-BEGIN
    height, width = img.shape[0: 2]
    x1, y1, z1 = np.dot(M, [0, 0, 1])
    x2, y2, z2 = np.dot(M, [width - 1, 0, 1])
    x3, y3, z3 = np.dot(M, [width - 1, height - 1, 1])
    x4, y4, z4 = np.dot(M, [0, height - 1, 1])
    if z1 != 0 and z2 != 0 and z3 != 0 and z4 != 0:
        x1 = x1 / z1
        y1 = y1 / z1
        x2 = x2 / z2
        y2 = y2 / z2
        x3 = x3 / z3
        y3 = y3 / z3
        x4 = x4 / z4
        y4 = y4 / z4
    minX = math.ceil(min(x1, x2, x3, x4))
    minY = math.ceil(min(y1, y2, y3, y4))
    maxX = math.ceil(max(x1, x2, x3, x4))
    maxY = math.ceil(max(y1, y2, y3, y4))
    # raise Exception("TODO in blend.py not implemented")
    # TODO-BLOCK-END
    return int(minX), int(minY), int(maxX), int(maxY)


def accumulateBlend(img, acc, M, blendWidth):
    """
       INPUT:
         img: image to add to the accumulator
         acc: portion of the accumulated image where img should be added
         M: the transformation mapping the input image to the accumulator
         blendWidth: width of blending function. horizontal hat function
       OUTPUT:
         modify acc with weighted copy of img added where the first
         three channels of acc record the weighted sum of the pixel colors
         and the fourth channel of acc records a sum of the weights
    """
    # BEGIN TODO 10
    # Fill in this routine
    # TODO-BLOCK-BEGIN
    h, w = img.shape[0: 2]
    minX, minY, maxX, maxY = imageBoundingBox(img, M)
    for i in range(minX, maxX + 1):
        for j in range(minY, maxY + 1):
            x, y, z = np.dot(np.linalg.inv(M), [i, j, 1])
            if z != 0:
                x = int(x / z)
                y = int(y / z)
            if x < 0 or x >= w - 1 or y < 0 or y >= h - 1:
                continue
            if img[y, x, 0] == 0 and img[y, x, 1] == 0 and img[y, x, 2] == 0:#all(img[y, x, :] == 0):
                continue
            weight = 1
            if minX <= x < minX + blendWidth:
                weight = float(x - minX) / blendWidth
            elif maxX >= x > maxX - blendWidth:
                weight = float(maxX - x) / blendWidth
            #else:
                #weight = 1
            acc[j, i, 3] += weight
            # acc[j, i, 0: 2] += img[y, x, 0: 2] * weight
            for k in range(3):
                acc[j, i, k] += img[y, x, k] * weight
    # raise Exception("TODO in blend.py not implemented")
    # TODO-BLOCK-END
    # END TODO


def normalizeBlend(acc):
    """
       INPUT:
         acc: input image whose alpha channel (4th channel) contains
         normalizing weight values
       OUTPUT:
         img: image with r,g,b values of acc normalized
    """
    # BEGIN TODO 11
    # fill in this routine..
    # TODO-BLOCK-BEGIN
    img = np.zeros((acc.shape[0], acc.shape[1], 3), dtype=np.uint8)
    for i in range(acc.shape[0]):
        for j in range(acc.shape[1]):
            if acc[i, j, 3] > 0:
                # img[i, j, 0: 3] = int(acc[i, j, 0: 3] / acc[i, j, 3])
                img[i, j, 0: 3] = (acc[i, j, 0: 3] / acc[i, j, 3]).astype(int)
    # raise Exception("TODO in blend.py not implemented")
    # TODO-BLOCK-END
    # END TODO
    return img


def getAccSize(ipv):
    """
       This function takes a list of ImageInfo objects consisting of images and
       corresponding transforms and Returns useful information about the accumulated
       image.

       INPUT:
         ipv: list of ImageInfo objects consisting of image (ImageInfo.img) and transform(image (ImageInfo.position))
       OUTPUT:
         accWidth: Width of accumulator image(minimum width such that all tranformed images lie within acc)
         accHeight: Height of accumulator image(minimum height such that all tranformed images lie within acc)

         channels: Number of channels in the accumulator image
         width: Width of each image(assumption: all input images have same width)
         translation: transformation matrix so that top-left corner of accumulator image is origin
    """

    # Compute bounding box for the mosaic
    minX = sys.maxsize
    minY = sys.maxsize
    maxX = 0
    maxY = 0
    channels = -1
    width = -1  # Assumes all images are the same width
    M = np.identity(3)
    for i in ipv:
        M = i.position
        img = i.img
        _, w, c = img.shape
        if channels == -1:
            channels = c
            width = w

        # BEGIN TODO 9
        # add some code here to update minX, ..., maxY
        # TODO-BLOCK-BEGIN
        minx, miny, maxx, maxy = imageBoundingBox(img, M)
        minX = minx if minx < minX else minX
        minY = miny if miny < minY else minY
        maxX = maxx if maxx > maxX else maxX
        maxY = maxy if maxy > maxY else maxY
        # raise Exception("TODO in blend.py not implemented")
        # TODO-BLOCK-END
        # END TODO

    # Create an accumulator image
    accWidth = int(math.ceil(maxX) - math.floor(minX))
    accHeight = int(math.ceil(maxY) - math.floor(minY))
    print('accWidth, accHeight:', (accWidth, accHeight))
    translation = np.array([[1, 0, -minX], [0, 1, -minY], [0, 0, 1]])

    return accWidth, accHeight, channels, width, translation


def pasteImages(ipv, translation, blendWidth, accWidth, accHeight, channels):
    acc = np.zeros((accHeight, accWidth, channels + 1))
    # Add in all the images
    M = np.identity(3)
    for count, i in enumerate(ipv):
        M = i.position
        img = i.img

        M_trans = translation.dot(M)
        accumulateBlend(img, acc, M_trans, blendWidth)

    return acc


def getDriftParams(ipv, translation, width):
    # Add in all the images
    M = np.identity(3)
    for count, i in enumerate(ipv):
        if count != 0 and count != (len(ipv) - 1):
            continue

        M = i.position

        M_trans = translation.dot(M)

        p = np.array([0.5 * width, 0, 1])
        p = M_trans.dot(p)

        # First image
        if count == 0:
            x_init, y_init = p[:2] / p[2]
        # Last image
        if count == (len(ipv) - 1):
            x_final, y_final = p[:2] / p[2]

    return x_init, y_init, x_final, y_final


def computeDrift(x_init, y_init, x_final, y_final, width):
    A = np.identity(3)
    drift = (float)(y_final - y_init)
    # We implicitly multiply by -1 if the order of the images is swapped...
    length = (float)(x_final - x_init)
    A[0, 2] = -0.5 * width
    # Negative because positive y points downwards
    A[1, 0] = -drift / length

    return A


def blendImages(ipv, blendWidth, is360=False, A_out=None):
    """
       INPUT:
         ipv: list of input images and their relative positions in the mosaic
         blendWidth: width of the blending function
       OUTPUT:
         croppedImage: final mosaic created by blending all images and
         correcting for any vertical drift
    """
    accWidth, accHeight, channels, width, translation = getAccSize(ipv)
    acc = pasteImages(
        ipv, translation, blendWidth, accWidth, accHeight, channels
    )
    compImage = normalizeBlend(acc)

    # Determine the final image width
    outputWidth = (accWidth - width) if is360 else accWidth
    x_init, y_init, x_final, y_final = getDriftParams(ipv, translation, width)
    # Compute the affine transform
    A = np.identity(3)
    # BEGIN TODO 12
    # fill in appropriate entries in A to trim the left edge and
    # to take out the vertical drift if this is a 360 panorama
    # (i.e. is360 is true)
    # Shift it left by the correct amount
    # Then handle the vertical drift
    # Note: warpPerspective does forward mapping which means A is an affine
    # transform that maps accumulator coordinates to final panorama coordinates
    # TODO-BLOCK-BEGIN
    if is360:
        A = computeDrift(x_init, y_init, x_final, y_final, width)
    # raise Exception("TODO in blend.py not implemented")
    # TODO-BLOCK-END
    # END TODO

    if A_out is not None:
        A_out[:] = A

    # Warp and crop the composite
    croppedImage = cv2.warpPerspective(
        compImage, A, (outputWidth, accHeight), flags=cv2.INTER_LINEAR
    )

    return croppedImage
