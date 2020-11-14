//
// Created by Zach on 11/13/2020.
//
#include "Image.h"
#include "string"
#include "fstream"
#include "iostream"
using namespace std;
Image OpenImage(const string& fileName);
void WriteImage(const Image& image, const string& fileName);
Image Multiply(const Image& top, const Image& bottom);
Image Subtract(const Image& top, const Image& bottom);
Image Screen(const Image& top, const Image& bottom);
Image Overlay(const Image& top, const Image& bottom);
Image FlatScaleColor(const Image& image, int channel, unsigned char amount);
Image ScaleColor(const Image& image, int channel, float scaleFactor);
Image Merge(const string& location1, const string& location2, const string& location3);
void Split(const Image& image, const string& location1, const string& location2, const string& location3);
Image Flip(const Image& image);



bool Test(const Image& attempt, const string& string1);
int main(){
    cout << "Completing Task 1" << endl;
    Image topLayer = OpenImage("input/layer1.tga");
    if(!Test(topLayer,"input/layer1.tga")){
        cout << "Ya Done Goofed on load 1";
    } else cout<< "Load one looks good";
    Image bottomLayer = OpenImage("input/pattern1.tga");
    if(!Test(bottomLayer,"input/pattern1.tga")){
        cout << "Ya Done Goofed on load 2";
    } else cout << "Load 2 looks good";
    Image task1 = Multiply(topLayer,bottomLayer);
    if(!Test(task1,"examples/EXAMPLE_part1.tga")){
        cout << "Ya Done Goofed";
    }
    WriteImage(task1,"output/part1.tga");

    cout << "Completing Task 2" << endl;
    topLayer = OpenImage("input/layer2.tga");
    if(!Test(topLayer,"input/layer2.tga")){
        cout << "Ya Done Goofed on load 1";
    } else cout<< "Load one looks good";
    bottomLayer = OpenImage("input/car.tga");
    if(!Test(bottomLayer,"input/car.tga")){
        cout << "Ya Done Goofed on load 2";
    } else cout << "Load 2 looks good";
    Image task2 = Subtract(topLayer,bottomLayer);
    if(!Test(task2,"examples/EXAMPLE_part2.tga")){
        cout << "Ya Done Goofed";
    }
    WriteImage(task1,"output/part2.tga");


    cout << "Completing Task 3" << endl;
    topLayer = OpenImage("input/layer1.tga");
    if(!Test(topLayer,"input/layer1.tga")){
        cout << "Ya Done Goofed on load 1";
    } else cout<< "Load one looks good";
    bottomLayer = OpenImage("input/pattern2.tga");
    if(!Test(bottomLayer,"input/pattern2.tga")){
        cout << "Ya Done Goofed on load 2";
    } else cout << "Load 2 looks good";
    Image temp3 = Multiply(topLayer,bottomLayer);
    topLayer = OpenImage("input/text.tga");
    if(!Test(topLayer,"input/text.tga")){
        cout << "Ya Done Goofed on load 3";
    } else cout<< "Load 3 looks good";
    Image Task3 = Screen(topLayer, temp3);
    if(!Test(task2,"examples/EXAMPLE_part3.tga")){
        cout << "Ya Done Goofed";
    }
    WriteImage(task1,"output/part3.tga");



    cout << "Completing Task 4" << endl;
    topLayer = OpenImage("input/layer2.tga");
    if(!Test(topLayer,"input/layer2.tga")){
        cout << "Ya Done Goofed on load 1";
    } else cout<< "Load one looks good";
    bottomLayer = OpenImage("input/circles.tga");
    if(!Test(bottomLayer,"input/circles.tga")){
        cout << "Ya Done Goofed on load 2";
    } else cout << "Load 2 looks good";
    Image temp4 = Multiply(topLayer,bottomLayer);
    topLayer = OpenImage("input/pattern2.tga");
    if(!Test(topLayer,"input/pattern2.tga")){
        cout << "Ya Done Goofed on load 3";
    } else cout<< "Load 3 looks good";
    Image task4 = Subtract(topLayer, temp4);
    if(!Test(task4,"examples/EXAMPLE_part4.tga")){
        cout << "Ya Done Goofed";
    }
    WriteImage(task1,"output/part4.tga");



    cout << "Completing Task 5" << endl;
    topLayer = OpenImage("input/layer1.tga");
    if(!Test(topLayer,"input/layer1.tga")){
        cout << "Ya Done Goofed on load 1";
    } else cout<< "Load one looks good";
    bottomLayer = OpenImage("input/pattern1.tga");
    if(!Test(bottomLayer,"input/pattern1.tga")){
        cout << "Ya Done Goofed on load 2";
    } else cout << "Load 2 looks good";
    Image task5 = Overlay(topLayer,bottomLayer);
    if(!Test(task5,"examples/EXAMPLE_part5.tga")){
        cout << "Ya Done Goofed";
    }
    WriteImage(task1,"output/part5.tga");



    cout << "Completing Task 6" << endl;
    topLayer = OpenImage("input/car.tga");
    if(!Test(topLayer,"input/car.tga")){
        cout << "Ya Done Goofed on load 1";
    } else cout<< "Load one looks good";
    Image task6 = FlatScaleColor(topLayer, 1, 200);
    if(!Test(task6,"examples/EXAMPLE_part6.tga")){
        cout << "Ya Done Goofed";
    }
    WriteImage(task1,"output/part6.tga");


    cout << "Completing Task 7" << endl;
    topLayer = OpenImage("input/car.tga");
    if(!Test(topLayer,"input/car.tga")){
        cout << "Ya Done Goofed on load 1";
    } else cout<< "Load one looks good";
    Image temp7 = ScaleColor(topLayer, 0, 4);
    Image task7 = ScaleColor(temp7, 2,0);
    if(!Test(task7,"examples/EXAMPLE_part7.tga")){
        cout << "Ya Done Goofed";
    }
    WriteImage(task1,"output/part7.tga");



    cout << "Completing Task 8" << endl;
    topLayer = OpenImage("input/car.tga");
    if(!Test(topLayer,"input/car.tga")){
        cout << "Ya Done Goofed on load 1";
    } else cout<< "Load one looks good";
    Split(topLayer,"output/part8_r.tga","output/part8_g.tga","output/part8_b.tga");



    cout << "Completing Task 9" << endl;
    Image task9 = Merge( "input/layer_red.tga",  "input/layer_green.tga", "input/layer_blue.tga");
    if(!Test(task4,"examples/EXAMPLE_part9.tga")){
        cout << "Ya Done Goofed";
    }
    WriteImage(task1,"output/part9.tga");

    cout << "Completing Task 10" << endl;
    topLayer = OpenImage("input/text2.tga");
    if(!Test(topLayer,"text2/car.tga")){
        cout << "Ya Done Goofed on load 1";
    } else cout<< "Load one looks good";
    Image task10 = Flip(topLayer);
    if(!Test(task10,"examples/EXAMPLE_part10.tga")){
        cout << "Ya Done Goofed";
    }
    WriteImage(task10,"output/part10.tga");


    return 1;
}



Image OpenImage(const string& fileName){
    ifstream file (fileName, ios::in | ios::binary);
    Image returnImage = Image();
    file.read(&returnImage.idLength, sizeof(returnImage.idLength));
    file.read(&returnImage.colorMapType, sizeof(returnImage.colorMapType));
    file.read(&returnImage.dataTypeCode, sizeof(returnImage.dataTypeCode));
    file.read((char*)&returnImage.colorMapOrigin, sizeof(returnImage.colorMapOrigin));
    file.read((char*)&returnImage.colorMapLength, sizeof(returnImage.colorMapLength));
    file.read(&returnImage.colorMapDepth, sizeof(returnImage.colorMapDepth));
    file.read((char*)&returnImage.xOrigin, sizeof(returnImage.xOrigin));
    file.read((char*)&returnImage.yOrigin, sizeof(returnImage.yOrigin));
    file.read((char*)&returnImage.width, sizeof(returnImage.width));
    file.read((char*)&returnImage.height, sizeof(returnImage.height));
    file.read(&returnImage.bitsPerPixel, sizeof(returnImage.bitsPerPixel));
    file.read(&returnImage.imageDescriptor, sizeof(returnImage.imageDescriptor));
    unsigned char redChar;
    unsigned char blueChar;
    unsigned char greenChar;

    for(short i = 0; i < returnImage.height;i++) {
        for (short j = 0; j < returnImage.width; j++) {
            file.read((char*)&redChar, sizeof(redChar));
            file.read((char*)&greenChar, sizeof(greenChar));
            file.read((char*)&blueChar, sizeof(blueChar));
            returnImage.redVec.push_back(redChar);
            returnImage.blueVec.push_back(blueChar);
            returnImage.greenVec.push_back(greenChar);
        }
    }
    return returnImage;
}




void WriteImage(const Image& image, const string& fileName){
    fstream file;
    file.open(fileName, ios::app | ios::binary);
    file.write(&image.idLength, sizeof(image.idLength));
    file.write(&image.colorMapType, sizeof(image.colorMapType));
    file.write(&image.dataTypeCode, sizeof(image.dataTypeCode));
    file.write((char*)&image.colorMapOrigin, sizeof(image.colorMapOrigin));
    file.write((char*)&image.colorMapLength, sizeof(image.colorMapLength));
    file.write(&image.colorMapDepth, sizeof(image.colorMapDepth));
    file.write((char*)&image.xOrigin, sizeof(image.xOrigin));
    file.write((char*)&image.yOrigin, sizeof(image.yOrigin));
    file.write((char*)&image.width, sizeof(image.width));
    file.write((char*)&image.height, sizeof(image.height));
    file.write(&image.bitsPerPixel, sizeof(image.bitsPerPixel));
    file.write(&image.imageDescriptor, sizeof(image.imageDescriptor));

    for(short i = 0; i < image.height;i++) {
        for (short j = 0; j < image.width; j++) {
            file.write((char*)&image.redVec[image.width*i + j], sizeof(unsigned char));
            file.write((char*)&image.greenVec[image.width*i + j], sizeof(unsigned char));
            file.write((char*)&image.blueVec[image.width*i + j], sizeof(unsigned char));
        }
    }
}




Image Multiply(const Image& top, const Image& bottom){
    Image returnImage = Image();
    returnImage.CopyHeader(top);


    for (short i = 0; i < top.height ; ++i) {
        for (short j = 0; j < top.width; ++j) {
            unsigned char redValTop;
            unsigned char greenValTop;
            unsigned char blueValTop;

            float scaledRedValTop;
            float scaledGreenValTop;
            float scaledBlueValTop;

            unsigned char redValBot;
            unsigned char greenValBot;
            unsigned char blueValBot;

            float scaledRedValBot;
            float scaledGreenValBot;
            float scaledBlueValBot;

            redValTop = top.redVec[top.width * i + j];
            greenValTop = top.greenVec[top.width * i + j];
            blueValTop = top.blueVec[top.width * i + j];

            redValBot = bottom.redVec[top.width * i + j];
            greenValBot = bottom.greenVec[top.width * i + j];
            blueValBot = bottom.blueVec[top.width * i + j];

            scaledRedValTop = redValTop / 255.0f;
            scaledGreenValTop = greenValTop / 255.0f;
            scaledBlueValTop = blueValTop / 255.0f;

            scaledRedValBot = redValBot / 255.0f;
            scaledGreenValBot = greenValBot / 255.0f;
            scaledBlueValBot = blueValBot / 255.0f;

            float redScaled = scaledRedValTop * scaledRedValBot;
            float blueScaled = scaledBlueValTop * scaledBlueValBot;
            float greenScaled = scaledGreenValTop * scaledGreenValBot;

            returnImage.redVec.push_back(255*redScaled + .5f);
            returnImage.greenVec.push_back(255*greenScaled + .5f);
            returnImage.blueVec.push_back(255*blueScaled + .5f);
        }
    }
    return returnImage;
}





bool Test(const Image& attempt, const string& string1){
    Image realImage = OpenImage(string1);
    if (realImage.idLength != attempt.idLength){
        return false;
    }
    if (realImage.colorMapType != attempt.colorMapType){
        return false;
    }
    if (realImage.dataTypeCode != attempt.dataTypeCode){
        return false;
    }
    if (realImage.colorMapOrigin != attempt.colorMapOrigin){
        return false;
    }
    if (realImage.colorMapLength != attempt.colorMapLength){
        return false;
    }
    if (realImage.colorMapDepth != attempt.colorMapDepth){
        return false;
    }
    if (realImage.xOrigin != attempt.xOrigin){
        return false;
    }
    if (realImage.yOrigin != attempt.yOrigin){
        return false;
    }
    if (realImage.width != attempt.width){
        return false;
    }
    if (realImage.height != attempt.height){
        return false;
    }
    if (realImage.bitsPerPixel != attempt.bitsPerPixel){
        return false;
    }
    if (realImage.imageDescriptor != attempt.imageDescriptor){
        return false;
    }
    for(short i = 0; i < realImage.height;i++) {
        for (short j = 0; j < realImage.width; j++) {
            if (realImage.redVec[realImage.width*i+j] != attempt.redVec[realImage.width*i+j]){
                cout << "Difference in Red at " << realImage.width*i+j << " By a value of " << realImage.redVec[realImage.width*i+j] - attempt.redVec[realImage.width*i+j] << endl;
            }
            if (realImage.greenVec[realImage.width*i+j] != attempt.greenVec[realImage.width*i+j]){
                cout << "Difference in Green at " << realImage.width*i+j << " By a value of " << realImage.redVec[realImage.width*i+j] - attempt.redVec[realImage.width*i+j] << endl;
            }
            if (realImage.blueVec[realImage.width*i+j] != attempt.blueVec[realImage.width*i+j]){
                cout << "Difference in Blue at " << realImage.width*i+j << " By a value of " << realImage.redVec[realImage.width*i+j] - attempt.redVec[realImage.width*i+j] << endl;
            }
        }
    }
    return true;
}





Image Subtract(const Image& top, const Image& bottom){
    // Bottom minus Top
    Image returnImage = Image();
    returnImage.CopyHeader(top);
    for (unsigned int i = 0; i < top.redVec.size(); ++i) {
        returnImage.redVec.push_back((unsigned char) ((unsigned int) bottom.redVec[i]-top.redVec[i]));
        returnImage.greenVec.push_back((unsigned char) ((unsigned int) bottom.greenVec[i]-top.greenVec[i]));
        returnImage.blueVec.push_back((unsigned char) ((unsigned int) bottom.blueVec[i]-top.blueVec[i]));
    }
    return returnImage;
}





Image Screen(const Image& top, const Image& bottom){
    Image returnImage = Image();
    returnImage.CopyHeader(top);


    for (short i = 0; i < top.height ; ++i) {
        for (short j = 0; j < top.width; ++j) {
            unsigned char redValTop;
            unsigned char greenValTop;
            unsigned char blueValTop;

            float scaledRedValTop;
            float scaledGreenValTop;
            float scaledBlueValTop;

            unsigned char redValBot;
            unsigned char greenValBot;
            unsigned char blueValBot;

            float scaledRedValBot;
            float scaledGreenValBot;
            float scaledBlueValBot;

            redValTop = top.redVec[top.width * i + j];
            greenValTop = top.greenVec[top.width * i + j];
            blueValTop = top.blueVec[top.width * i + j];

            redValBot = bottom.redVec[top.width * i + j];
            greenValBot = bottom.greenVec[top.width * i + j];
            blueValBot = bottom.blueVec[top.width * i + j];

            scaledRedValTop = 1-(redValTop / 255.0f);
            scaledGreenValTop = 1-(greenValTop / 255.0f);
            scaledBlueValTop = 1-(blueValTop / 255.0f);

            scaledRedValBot = 1-( redValBot / 255.0f);
            scaledGreenValBot = 1 - (greenValBot / 255.0f);
            scaledBlueValBot = 1 - ( blueValBot / 255.0f);

            float redScaled = 1-(scaledRedValTop * scaledRedValBot);
            float blueScaled = 1-(scaledBlueValTop * scaledBlueValBot);
            float greenScaled = 1-(scaledGreenValTop * scaledGreenValBot);

            returnImage.redVec.push_back(255*redScaled + .5f);
            returnImage.greenVec.push_back(255*greenScaled + .5f);
            returnImage.blueVec.push_back(255*blueScaled + .5f);
        }
    }
    return returnImage;
}





Image Overlay(const Image& top, const Image& bottom){
    Image returnImage = Image();
    returnImage.CopyHeader(top);
    for (short i = 0; i < top.height ; ++i) {
        for (short j = 0; j < top.width; ++j) {
            unsigned char redValTop;
            unsigned char greenValTop;
            unsigned char blueValTop;

            float scaledRedValTop;
            float scaledGreenValTop;
            float scaledBlueValTop;

            unsigned char redValBot;
            unsigned char greenValBot;
            unsigned char blueValBot;

            float scaledRedValBot;
            float scaledGreenValBot;
            float scaledBlueValBot;

            redValTop = top.redVec[top.width * i + j];
            greenValTop = top.greenVec[top.width * i + j];
            blueValTop = top.blueVec[top.width * i + j];

            redValBot = bottom.redVec[top.width * i + j];
            greenValBot = bottom.greenVec[top.width * i + j];
            blueValBot = bottom.blueVec[top.width * i + j];

            scaledRedValTop = (redValTop / 255.0f);
            scaledGreenValTop = (greenValTop / 255.0f);
            scaledBlueValTop = (blueValTop / 255.0f);

            scaledRedValBot = (redValBot / 255.0f);
            scaledGreenValBot = (greenValBot / 255.0f);
            scaledBlueValBot = ( blueValBot / 255.0f);
            float redScaled;
            float greenScaled;
            float blueScaled;
            if (scaledRedValBot < .5){
                redScaled = 2 * (scaledRedValTop * scaledRedValBot);
            }
            else{
                 redScaled = 1-(2*((1-scaledRedValTop)*(1-scaledRedValBot)));
            }
            if (scaledGreenValBot < .5){
                greenScaled = 2 * (scaledGreenValTop * scaledGreenValBot);
            }
            else{
                greenScaled = 1-(2*((1-scaledGreenValTop)*(1-scaledGreenValBot)));
            }
            if (scaledBlueValBot < .5){
                blueScaled = 2 * (scaledBlueValTop * scaledBlueValBot);
            }
            else{
                blueScaled = 1-(2*((1-scaledBlueValTop)*(1-scaledBlueValBot)));
            }
            returnImage.redVec.push_back(255*redScaled + .5f);
            returnImage.greenVec.push_back(255*greenScaled + .5f);
            returnImage.blueVec.push_back(255*blueScaled + .5f);
        }
    }
    return returnImage;
}




Image FlatScaleColor(const Image& image, int channel, unsigned char amount){
    Image returnImage = Image();
    returnImage.CopyHeader(image);
    if (channel == 0){
        for (int i = 0; i < image.redVec.size(); ++i) {
            returnImage.redVec.push_back(image.redVec[i] + amount);
            returnImage.greenVec.push_back(image.greenVec[i]);
            returnImage.blueVec.push_back(image.blueVec[i]);


        }
    }
    else if(channel ==1){
        for (int i = 0; i < image.redVec.size(); ++i) {
            returnImage.greenVec.push_back(image.greenVec[i] + amount);
            returnImage.redVec.push_back(image.redVec[i]);
            returnImage.blueVec.push_back(image.blueVec[i]);
        }
    }
    else if (channel == 2){
            for (int i = 0; i < image.redVec.size(); ++i) {
                returnImage.blueVec.push_back(image.blueVec[i] + amount);
                returnImage.greenVec.push_back(image.greenVec[i]);
                returnImage.redVec.push_back(image.redVec[i]);
        }
    }
    return returnImage;
}





Image ScaleColor(const Image& image, int channel, float scaleFactor){
    Image returnImage = Image();
    returnImage.CopyHeader(image);
    if (channel == 0){
        for (int i = 0; i < image.redVec.size(); ++i) {
            unsigned char redValTop;
            float scaledRedValTop;

            redValTop = image.redVec[i];
            scaledRedValTop = redValTop / 255.0f;
            scaledRedValTop = scaledRedValTop * scaleFactor;

            returnImage.redVec.push_back(255*scaledRedValTop + .5f);
            returnImage.greenVec.push_back(image.greenVec[i]);
            returnImage.blueVec.push_back(image.blueVec[i]);
        }
    }
    else if(channel ==1){
        for (int i = 0; i < image.redVec.size(); ++i) {
            unsigned char redValTop;
            float scaledRedValTop;

            redValTop = image.greenVec[i];
            scaledRedValTop = redValTop / 255.0f;
            scaledRedValTop = scaledRedValTop * scaleFactor;


            returnImage.greenVec.push_back(255*scaledRedValTop + .5f);
            returnImage.redVec.push_back(image.redVec[i]);
            returnImage.blueVec.push_back(image.blueVec[i]);
        }
    }
    else if (channel == 2){
        for (int i = 0; i < image.redVec.size(); ++i) {
            unsigned char redValTop;
            float scaledRedValTop;

            redValTop = image.blueVec[i];
            scaledRedValTop = redValTop / 255.0f;
            scaledRedValTop = scaledRedValTop * scaleFactor;

            returnImage.blueVec.push_back(255*scaledRedValTop + .5f);
            returnImage.greenVec.push_back(image.greenVec[i]);
            returnImage.redVec.push_back(image.redVec[i]);
        }
    }
    return returnImage;

}





Image Merge(const string& location1, const string& location2, const string& location3){
    Image Image1 = OpenImage(location1);
    Image Image2 = OpenImage(location2);
    Image Image3 = OpenImage(location3);

    Image returnImage = Image();
    returnImage.CopyHeader(Image1);

    for (unsigned int i = 0; i < Image1.redVec.size(); ++i) {
        returnImage.redVec.push_back(Image1.redVec[i]);
        returnImage.greenVec.push_back(Image2.greenVec[i]);
        returnImage.blueVec.push_back(Image3.blueVec[i]);
    }
    return returnImage;
}




void Split(const Image& image,const string& location1, const string& location2, const string& location3){
    Image image1 = Image();
    Image image2 = Image();
    Image image3 = Image();

    for (unsigned int i = 0; i < image.redVec.size(); ++i) {
        image1.redVec.push_back(image.redVec[i]);
        image2.greenVec.push_back(image.greenVec[i]);
        image3.blueVec.push_back(image.blueVec[i]);
    }

    image1.greenVec = std::vector<unsigned char> (image1.redVec.size(), 0);
    image1.blueVec = std::vector<unsigned char> (image1.redVec.size(), 0);

    image2.redVec = std::vector<unsigned char> (image2.greenVec.size(), 0);
    image2.blueVec = std::vector<unsigned char> (image2.greenVec.size(), 0);

    image3.greenVec = std::vector<unsigned char> (image3.blueVec.size(), 0);
    image3.redVec = std::vector<unsigned char> (image3.blueVec.size(), 0);

    WriteImage(image1, location1);
    WriteImage(image2, location2);
    WriteImage(image3, location3);
}
Image Flip(const Image& image){
    Image returnImage = Image();
    returnImage.CopyHeader(image);

    for (short  i = image.height;i > 0; i--) {
        for (short j = image.width; j > 0; j--) {
            returnImage.redVec.push_back(image.redVec[image.width*i + j]);
            returnImage.greenVec.push_back(image.greenVec[image.width*i + j]);
            returnImage.blueVec.push_back(image.blueVec[image.width*i + j]);
        }
    }
    return returnImage;
}