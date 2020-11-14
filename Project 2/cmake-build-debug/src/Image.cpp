//
// Created by Zach on 11/13/2020.
//

#include "Image.h"

Image::Image() {
     idLength = 0;
     colorMapType = 0;
     dataTypeCode = 0;
     colorMapOrigin = 0;
     colorMapLength = 0;
     colorMapDepth = 0;
     xOrigin = 0;
     yOrigin = 0;
     width = 0;
     height = 0;
     bitsPerPixel = 0;
     imageDescriptor = 0;
     redVec = std::vector<unsigned char>(0);
     greenVec  = std::vector<unsigned char> (0);
     blueVec = std::vector<unsigned char> (0);

}

void Image::CopyHeader(const Image &i) {
    idLength = i.idLength;
    colorMapType = i.colorMapType;
    dataTypeCode = i.dataTypeCode;
    colorMapOrigin = i.colorMapOrigin;
    colorMapLength = i.colorMapLength;
    colorMapDepth = i.colorMapDepth;
    xOrigin = i.xOrigin;
    yOrigin = i.yOrigin;
    width = i.width;
    height = i.height;
    bitsPerPixel = i.bitsPerPixel;
    imageDescriptor = i.imageDescriptor;





}
