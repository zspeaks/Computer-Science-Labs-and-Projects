//
// Created by Zach on 11/13/2020.
//

#ifndef PROJECT2_IMAGE_H
#define PROJECT2_IMAGE_H
#include "vector"

class Image {
private:

public:
    char idLength;
    char colorMapType;
    char dataTypeCode;
    short colorMapOrigin;
    short colorMapLength;
    char colorMapDepth;
    short xOrigin;
    short yOrigin;
    short width;
    short height;
    char bitsPerPixel;
    char imageDescriptor;
    std::vector<unsigned char> redVec;
    std::vector<unsigned char> greenVec;
    std::vector<unsigned char> blueVec;

    Image();
    void CopyHeader(const Image& i);

};


#endif //PROJECT2_IMAGE_H
