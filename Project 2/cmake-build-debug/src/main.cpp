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
Image Join(const string& string1,const string& string2,const string& string3,const string& string4);



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
    WriteImage(task2,"output/part2.tga");


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
    Image task3 = Screen(topLayer, temp3);
    if(!Test(task3,"examples/EXAMPLE_part3.tga")){
        cout << "Ya Done Goofed";
    }
    WriteImage(task3,"output/part3.tga");



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
    WriteImage(task4,"output/part4.tga");



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
    WriteImage(task5,"output/part5.tga");



    cout << "Completing Task 6" << endl;
    topLayer = OpenImage("input/car.tga");
    if(!Test(topLayer,"input/car.tga")){
        cout << "Ya Done Goofed on load 1";
    } else cout<< "Load one looks good";
    Image task6 = FlatScaleColor(topLayer, 1, 200);
    if(!Test(task6,"examples/EXAMPLE_part6.tga")){
        cout << "Ya Done Goofed";
    }
    WriteImage(task6,"output/part6.tga");


    cout << "Completing Task 7" << endl;
    topLayer = OpenImage("input/car.tga");
    if(!Test(topLayer,"input/car.tga")){
        cout << "Ya Done Goofed on load 1";
    } else cout<< "Load one looks good";
    Image task7 = ScaleColor(topLayer, 2, 4);
    if(!Test(task7,"examples/EXAMPLE_part7.tga")){
        cout << "Ya Done Goofed";
    }
    WriteImage(task7,"output/part7.tga");



    cout << "Completing Task 8" << endl;
    topLayer = OpenImage("input/car.tga");
    if(!Test(topLayer,"input/car.tga")){
        cout << "Ya Done Goofed on load 1";
    } else cout<< "Load one looks good";
    Split(topLayer,"output/part8_r.tga","output/part8_g.tga","output/part8_b.tga");



    cout << "Completing Task 9" << endl;
    Image task9 = Merge( "input/layer_red.tga",  "input/layer_green.tga", "input/layer_blue.tga");
    if(!Test(task9,"examples/EXAMPLE_part9.tga")){
        cout << "Ya Done Goofed";
    }
    WriteImage(task9,"output/part9.tga");

    cout << "Completing Task 10" << endl;
    topLayer = OpenImage("input/text2.tga");
    if(!Test(topLayer,"input/text2.tga")){
        cout << "Ya Done Goofed on load 1";
    } else cout<< "Load one looks good";
    Image task10 = Flip(topLayer);
    if(!Test(task10,"examples/EXAMPLE_part10.tga")){
        cout << "Ya Done Goofed";
    }
    WriteImage(task10,"output/part10.tga");

    cout << "Completing EC" << endl;
    Image task11 = Join("input/text.tga", "input/pattern1.tga", "input/car.tga","input/circles.tga");
    Test(task11, "examples/EXAMPLE_extracredit.tga");
    WriteImage(task11,"output/extracredit.tga");


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
            file.read((char*)&blueChar, sizeof(blueChar));
            file.read((char*)&greenChar, sizeof(greenChar));
            file.read((char*)&redChar, sizeof(redChar));
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
            file.write((char*)&image.blueVec[image.width*i + j], sizeof(unsigned char));
            file.write((char*)&image.greenVec[image.width*i + j], sizeof(unsigned char));
            file.write((char*)&image.redVec[image.width*i + j], sizeof(unsigned char));
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
        int redDiff = bottom.redVec[i]-top.redVec[i];
        if (redDiff < 0){
            redDiff = 0;
        }
        int greenDiff = bottom.greenVec[i]-top.greenVec[i];
        if (greenDiff < 0){
            greenDiff = 0;
        }
        int blueDiff = bottom.blueVec[i]-top.blueVec[i];
        if (blueDiff < 0){
            blueDiff = 0;
        }

        returnImage.redVec.push_back((unsigned char)redDiff);
        returnImage.greenVec.push_back((unsigned char) greenDiff);
        returnImage.blueVec.push_back((unsigned char) blueDiff);
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
            int greenNew = image.greenVec[i] + amount;
            if (greenNew > 255){
                greenNew = 255;
            }
            returnImage.greenVec.push_back(greenNew);
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
    for (unsigned int i = 0; i < image.redVec.size(); ++i) {
        float tempRed = 4.0f * image.redVec[i];
        if (tempRed > 255){
            tempRed = 255;
        }
        returnImage.redVec.push_back((unsigned char)tempRed);
        returnImage.greenVec.push_back(image.greenVec[i]);
        returnImage.blueVec.push_back(0);
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

    image1.CopyHeader(image);
    image2.CopyHeader(image);
    image3.CopyHeader(image);

    for (unsigned int i = 0; i < image.redVec.size(); ++i) {
        image1.redVec.push_back(image.redVec[i]);
        image1.blueVec.push_back(image.redVec[i]);
        image1.greenVec.push_back(image.redVec[i]);

        image2.redVec.push_back(image.greenVec[i]);
        image2.blueVec.push_back(image.greenVec[i]);
        image2.greenVec.push_back(image.greenVec[i]);

        image3.redVec.push_back(image.blueVec[i]);
        image3.blueVec.push_back(image.blueVec[i]);
        image3.greenVec.push_back(image.blueVec[i]);

    }
    Test(image1, "examples/EXAMPLE_part8_r.tga");
    Test(image2, "examples/EXAMPLE_part8_g.tga");
    Test(image3, "examples/EXAMPLE_part8_b.tga");




    WriteImage(image1, location1);
    WriteImage(image2, location2);
    WriteImage(image3, location3);
}
Image Flip(const Image& image){
    Image returnImage = Image();
    returnImage.CopyHeader(image);

    for (unsigned int i = 0;i<image.redVec.size();i++){
        returnImage.redVec.push_back(image.redVec[image.redVec.size() - 1 -i]);
        returnImage.greenVec.push_back(image.greenVec[image.redVec.size() - 1 -i]);
        returnImage.blueVec.push_back(image.blueVec[image.redVec.size() - 1 -i]);
    }
    return returnImage;
}

Image Join(const string& string1,const string& string2,const string& string3,const string& string4){
    Image text = OpenImage(string1);
    Image pattern = OpenImage(string2);
    Image car = OpenImage(string3);
    Image circles = OpenImage(string4);

    Image returnImage = Image();
    returnImage.CopyHeader(text);
    returnImage.height = 2 * returnImage.height;
    returnImage.width = 2 * returnImage.width;

    for (short i = 0; i < returnImage.height; ++i) {
        for (short j = 0; j < returnImage.width; ++j) {
            if (i < text.height){
                if (j < text.width){
                    returnImage.redVec.push_back(text.redVec[i*text.width + j]);
                    returnImage.greenVec.push_back(text.greenVec[i*text.width + j]);
                    returnImage.blueVec.push_back(text.blueVec[i*text.width + j]);
                } else{
                    returnImage.redVec.push_back(pattern.redVec[i*text.width + (j-text.width)]);
                    returnImage.greenVec.push_back(pattern.greenVec[i*text.width + (j-text.width)]);
                    returnImage.blueVec.push_back(pattern.blueVec[i*text.width + (j-text.width)]);
                }
            } else{
                if (j < car.width){
                    returnImage.redVec.push_back(car.redVec[(i-text.height)*text.width + j]);
                    returnImage.greenVec.push_back(car.greenVec[(i-text.height)*text.width + j]);
                    returnImage.blueVec.push_back(car.blueVec[(i-text.height)*text.width + j]);

                } else{
                    returnImage.redVec.push_back(circles.redVec[(i-text.height)*text.width + (j-text.width)]);
                    returnImage.greenVec.push_back(circles.greenVec[(i-text.height)*text.width + (j-text.width)]);
                    returnImage.blueVec.push_back(circles.blueVec[(i-text.height)*text.width + (j-text.width)]);

                }
            }


        }
    }
    return returnImage;
}
