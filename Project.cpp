
/************************************************************************************
 
 File:             Project
 
 Description:    A complete OpenGL program to exhibit openGL lighting.
 
 Author:          Zesheng Jia A00416452
 
 *************************************************************************************/



/* include the library header files */
#include <stdlib.h>
#include <stdio.h>
#include <GLUT/GLUT.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>
#include <cstdlib>

using namespace std;

// messagePrint
bool messagePrint = false;
bool messageLeftPrint = false;

// demo test
int demoTest = 0;
// demo start
int demoStart = 0;
int moutainOn = 0;
// calculation of plane
int verticesNumOfPlane = 0;
int verticesNumOfProp = 0;
int facesNumOfPlane = 0;
int facesNumOfProp = 0;
int polygonsNumOfPlane = 0;
int polygonsNumOfProp = 0;

// distance radius
GLfloat radius = 3;
//PI
const double PI = 3.14159265;
// angle const
const double angleConst = PI / 180;
// current camera position
GLfloat cameraPosition[] = {
    1 , 2 , 0
//    2, 0 , 0
//    0,1,0
//    0,0,1
    
};
// camera/position speed
GLfloat caPoMoveSpeedOn = 0;

// camera/position move speed
GLfloat caPoMoveSpeed = 0.01;
// camera/position default move speed
GLfloat caPoMoveDefaultSpeed = 0.01;

// camera/position move up speed
GLfloat caPoMoveUpSpeed = 0.01;

// camera/position move up/down
GLfloat caPoMoveUpDown = 0;
// camera/postion move left/right
GLfloat caPoMoveLeftRight = 0;
// camera/postion move left/right value
GLfloat caPoMoveLeftRightRotateValue = 0;
// camera/postion move speed
GLfloat caPoMoveLeftRightSpeed = 0.01;
// mouse angle translate
GLfloat turningAngle = 0;

// DiskOn
int DiskOn = 0;
// camera/position gear
GLfloat gear[] = {
    0.01 ,
    0.04 ,
    0.06 ,
    0.08
};
int gearOn = 1;

// camera/position move up/down speed
//GLfloat  caPoMoveSpeed = caPoMoveSpeed;
// eye postion
GLfloat eyePositon[3] = {
    0 , 1 , 0
};

// window dimensions
GLint windowWidth  = 800;
GLint windowHeight = 400;
// default window dimmension
GLint OwindowWidth  = 800;
GLint OwindowHeight = 400;

//Plane postion vector
GLfloat planePostionTranslate[3] = {
    0, 1 , 0
//    0, 0, 0
};
//Plane postion Roate
GLfloat planePostionRoate[4] = {
     0 , 0 , 1, 0
//    0 , 0 , 0, 0
};

// plane tilt mode
int tiltMode = 0;
// plane tilt speed
GLfloat planeTiltSpeed [4] = {
    // up speed
    -0.1 ,
    // down speed
    0.1
};

// plane tilt angle
GLfloat planeTiltAngle[][4] = {
    {0, 1 , 0 , 0} , // left right
    {0, 0 , 1 , 0} , // level left right
    {0, 0 , 0 , 1}  // up down
};

// propeller rotating angle
GLfloat theta = 0;
// propeller ratating speed
GLfloat delta = 5;
// propeller color
GLfloat propellColor[][4] = {
    {0.9568627451 , 0.137254902 , 0 , 1 } ,
    { 0.4980392157, 0.8352941176 , 0.2431372549 ,  1}
};

// Size of Grid
 const int gridSize = 100;
// Vertices of Grid
GLfloat grid[gridSize+1][gridSize+1][3];
// size of rate
GLfloat rate = 1;

// are we using smooth shading or flat?
int smoothOn = 0;
// are we frame or solid
int frameOn = 1;
// Full Screen or windowed mode
int fullScreenOn = 0;
// fog On
int fogOn = 1;

// Lines at original point

GLfloat colors[][4] = {
    {1 , 0 , 0 , 1} , {0 , 1 , 0 , 1} , {0 , 0 , 1 , 1}
};
GLfloat linesAtOriginal[][3] = {
     {0  , 0  , 0 } ,
     {1  , 0  , 0 } ,
    {0  , 1  , 0 } ,
    {0  , 0  , 1 },
   
};



// Models vertices and normals

GLfloat cessna[6763][3];

GLfloat normals[6763][3];

GLfloat transparence = 0.8;
// cessna color
GLfloat cessnaColor[33][4] = {
    //yellow 1
    {1 , 0.8078431373 ,0.2588235294 , transparence} , // 0
    {1 , 0.8078431373 ,0.2588235294 , transparence} , // 1
    {1 , 0.8078431373 ,0.2588235294 , transparence} , // 2
    {1 , 0.8078431373 ,0.2588235294 , transparence} , // 3
    // black 4-5
    {0.1568627451 , 0.168627451 , 0.2039215686 , transparence} , // 4
    {0.1568627451 , 0.168627451 , 0.2039215686 , transparence} , // 5
    // light purple 6
    {0.6509803922 , 0.4196078431 , 0.8 , transparence} , //6
    // blue 7
    {0.2666666667 , 0.1921568627 , 0.968627451 , transparence} , //7
    // yellow 8 - 13
    {1 , 0.8078431373 ,0.2588235294 , transparence} , // 8
    {1 , 0.8078431373 ,0.2588235294 , transparence} , // 9
    {1 , 0.8078431373 ,0.2588235294, transparence } , // 10
    {1 , 0.8078431373 ,0.2588235294 , transparence} , // 11
    {1 , 0.8078431373 ,0.2588235294 , transparence} , // 12
    {1 , 0.8078431373 ,0.2588235294 , transparence} , // 13
    // blue 14 - 25
    {0.2666666667 , 0.1921568627 , 0.968627451, transparence} , //14
    {0.2666666667 , 0.1921568627 , 0.968627451, transparence} , //15
    {0.2666666667 , 0.1921568627 , 0.968627451, transparence} , //16
    {0.2666666667 , 0.1921568627 , 0.968627451, transparence} , //17
    {0.2666666667 , 0.1921568627 , 0.968627451, transparence} , //18
    {0.2666666667 , 0.1921568627 , 0.968627451, transparence} , //19
    {0.2666666667 , 0.1921568627 , 0.968627451, transparence} , //20
    {0.2666666667 , 0.1921568627 , 0.968627451, transparence} , //21
    {0.2666666667 , 0.1921568627 , 0.968627451, transparence} , //22
    {0.2666666667 , 0.1921568627 , 0.968627451, transparence} , //23
    {0.2666666667 , 0.1921568627 , 0.968627451, transparence} , //24
    {0.2666666667 , 0.1921568627 , 0.968627451, transparence} , //25
    // yellow 26 - 32
    {1 , 0.8078431373 ,0.2588235294, transparence } , // 26
    {1 , 0.8078431373 ,0.2588235294 , transparence} , // 27
    {1 , 0.8078431373 ,0.2588235294 , transparence} , // 28
    {1 , 0.8078431373 ,0.2588235294 , transparence} , // 29
    {1 , 0.8078431373 ,0.2588235294 , transparence} , // 30
    {1 , 0.8078431373 ,0.2588235294 , transparence} , // 31
    {1 , 0.8078431373 ,0.2588235294 , transparence} , // 32
};




// object
vector<vector<vector<int>>> object;
// one subject
vector<vector<int>> g;
// one polygon
vector<int> f;

// object
vector<vector<vector<int>>> propellerObject;
// one subject
vector<vector<int>> propellerG;
// one polygon
vector<int> propellerF;


//  position the light source at the origin
GLfloat lightPosition[] = { 10.0, 10.0, 10.0, 1.0 };

// a material that is all zeros
GLfloat zeroMaterial[]    = { 0.0, 0.0, 0.0, 1.0 };

// a red ambient material
GLfloat redAmbient[]    = { 0.83, 0.0, 0.0, 1.0 };

// a blue diffuse material
GLfloat blueDiffuse[]    = { 0.1, 0.5, 0.8, 1.0 };

// a red diffuse material
GLfloat redDiffuse[]    = { 1.0, 0.0, 0.0, 1.0 };

// a white specular material
GLfloat whiteSpecular[]    = { 1.0, 1.0, 1.0, 1.0 };


// the degrees of shinnines (size of the specular highlight, bigger number means smaller highlight)
GLfloat noShininess        =  0.0;
GLfloat highShininess    = 100.0;
GLfloat PlaneShininess    = 20.0;

// TextTure

// image size
int SkyImageWidth, SkyImageHeight;
int SeaImageWidth, SeaImageHeight;
int MountainImageWidth, MountainImageHeight;
// the image data
GLubyte *imageDataOfSea;
GLubyte *imageDataOfSky;
GLubyte *imageDataOfMountain;
// the texture IDs
GLuint seaTextureID;
GLuint skyTextureID;
GLuint MountainTextureID;

// Tool Functions
// number of recursive steps
#define RECURSIVE_LEVELS 3

// a point data type
typedef GLfloat point2[3];
// initial polygon
point2 polygon1[] = {{10, 0, 10},
    {10, 0 , 20},
    {20,0 , 20} ,
    {20, 0 ,10 }};

void drawpolygon(point2 a, point2 b, point2 c , point2 d)
{
    // display one polygon
    
    GLfloat colorDiffuse1[] =  {0, 0.898039215686275, 0, 1};
    glMaterialfv(GL_FRONT, GL_AMBIENT,   colorDiffuse1);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   colorDiffuse1); //whiteTranslucent);
    glMaterialfv(GL_FRONT, GL_SPECULAR,   whiteSpecular);
    glMaterialf(GL_FRONT,  GL_SHININESS, highShininess);
    glBegin(GL_POLYGON);
    glVertex3fv(a);
    glVertex3fv(b);
    glVertex3fv(c);
    glVertex3fv(d);
    glEnd();
}

/************************************************************************
 
 Function:        dividepolygon
 
 Description:    divide up the polygon using the Sierpinski agasket
 algorithm.
 
 *************************************************************************/
void dividepolygon(point2 a, point2 b, point2 c, point2 d, int level)
{
    // polygon subdivision using edge midpoints
    point2 m0, m1, m2 , m3 , m4;
    
    // counter for each of the two point components
    int j;
    
    if (level > 0)  // still need to divide the polygon further
    {
        
        for(j=0; j<=3; j++)  m0[j]=(a[j]+b[j])/2;
        for(j=0; j<=3; j++)  m1[j]=(b[j]+c[j])/2;
        for(j=0; j<=3; j++)  m2[j]=(c[j]+d[j])/2;
        for(j=0; j<=3; j++)  m3[j]=(d[j]+a[j])/2;
        
        m4[0] = (b[0] + c[0])/2;
        m4[2] = 1;
        
        // recurse on each of the 3 sub-polygons
        dividepolygon(a, m0, m4, m3, level-1);
        dividepolygon(m0, b ,m1, m4,  level-1);
        dividepolygon(m4, m1 , c , m2, level-1);
        dividepolygon(m3, m4, m2, d,  level-1);
        
        printf(" %f %f  b c\n" , b[0] , c[0]);
        printf(" %f %f  b a\n" , b[1] , a[1]);
        printf(" %f %f  4 4\n" , m4[0] , m4[1]);
    }
    else
        // draw polygon at end of recursion
        drawpolygon(a,b,c,d);
    //     printf(" %f %3f %3f %3f \n " , a, b, c,d);
}


/************************************************************************
 
 Function:        loadImage
 
 Description:    load PPM image
 
 *************************************************************************/


void loadImage(string path , GLubyte* &imageData , int* imageWidth, int* imageHeight)
{
    
    
    // the ID of the image file
    FILE *fileID;
    
    // maxValue
    int  maxValue;
    
    // total number of pixels in the image
    int  totalPixels;
    
    // temporary character
    char tempChar;
    
    // counter variable for the current pixel in the image
    int i;
    
    // array for reading in header information
    char headerLine[100];
    
    float RGBScaling;
    
    // temporary variables for reading in the red, green and blue data of each pixel
    int red, green, blue;
    
    // open the image file for reading
    fileID = fopen(path.c_str(), "r");
    
    // read in the first header line
    fscanf(fileID,"%[^\n] ", headerLine);
    
    // make sure that the image begins with 'P3', which signifies a PPM file
    if ((headerLine[0] != 'P') || (headerLine[1] != '3'))
    {
        printf("This is not a PPM file!\n");
        exit(0);
    }
    
    // we have a PPM file
    printf("This is a PPM file\n");
    
    // read in the first character of the next line
    fscanf(fileID, "%c", &tempChar);
    
    // while we still have comment lines (which begin with #)
    while(tempChar == '#')
    {
        // read in the comment
        fscanf(fileID, "%[^\n] ", headerLine);
        
        // print the comment
        printf("%s\n", headerLine);
        
        // read in the first character of the next line
        fscanf(fileID, "%c",&tempChar);
    }
    
    // the last one was not a comment character '#', so we need to put it back into the file stream (undo)
    ungetc(tempChar, fileID);
    
    // read in the image hieght, width and the maximum value
    fscanf(fileID, "%d %d %d", &*imageWidth, &*imageHeight, &maxValue);
    
    // print out the information about the image file
    printf("%d rows  %d columns  max value= %d\n", *imageHeight, *imageWidth, maxValue);
    
    // compute the total number of pixels in the image
    totalPixels = *imageWidth * *imageHeight;
    
    // allocate enough memory for the image  (3*) because of the RGB data
    imageData = (GLubyte*)malloc(3 * sizeof(GLuint) * totalPixels);
    
    // determine the scaling for RGB values
    RGBScaling = 255.0 / maxValue;
    
    
    // if the maxValue is 255 then we do not need to scale the
    //    image data values to be in the range or 0 to 255
    if (maxValue == 255)
    {
        for(i = 0; i < totalPixels; i++)
        {
            // read in the current pixel from the file
            fscanf(fileID,"%d %d %d",&red, &green, &blue );
            
            // store the red, green and blue data of the current pixel in the data array
            imageData[3*totalPixels - 3*i - 3] = red;
            imageData[3*totalPixels - 3*i - 2] = green;
            imageData[3*totalPixels - 3*i - 1] = blue;
        }
    }
    else  // need to scale up the data values
    {
        for(i = 0; i < totalPixels; i++)
        {
            // read in the current pixel from the file
            fscanf(fileID,"%d %d %d",&red, &green, &blue );
            
            // store the red, green and blue data of the current pixel in the data array
            imageData[3*totalPixels - 3*i - 3] = red   * RGBScaling;
            imageData[3*totalPixels - 3*i - 2] = green * RGBScaling;
            imageData[3*totalPixels - 3*i - 1] = blue  * RGBScaling;
        }
    }
    
    
    // close the image file
    fclose(fileID);
}



/************************************************************************
 
 Function:        createSeaTexture
 
 Description:    Contruct a blue random texture.
 
 *************************************************************************/
void createSeaTexture()
{
    
    // make space for texture
    GLubyte myTexture[SeaImageWidth][SeaImageHeight][3];
    int u, v , i = 0;
    
    // enable texture mapping
    glEnable(GL_TEXTURE_2D);
    
    // for each texture element
    for(u = 0; u < SeaImageWidth; u++)
    {
        for(v = 0; v < SeaImageHeight; v++)
        {
            // assign a random color, except for BLUE
            myTexture[u][v][0] =  imageDataOfSea[i];
            myTexture[u][v][1] =  imageDataOfSea[i + 1];
            myTexture[u][v][2] =  imageDataOfSea[i + 2];
            i += 3;
        }
    }
    
    // generate texture ID
    glGenTextures(1, &seaTextureID);
    
    // set the blue texture to be current
    glBindTexture(GL_TEXTURE_2D, seaTextureID);
    
    // tell openGL how to scale the texture image up if needed
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    // tell openGL how to scale the texture image down if needed
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    
    
    // build mipmaps for the current texture
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, SeaImageWidth, SeaImageHeight,
                      GL_RGB, GL_UNSIGNED_BYTE, myTexture);
    
    
     glDisable(GL_TEXTURE_2D);
}


/************************************************************************
 
 Function:        createSkyTexture
 
 Description:    Contruct a blue random texture.
 
 *************************************************************************/
void createSkyTexture()
{

    // make space for texture
    GLubyte myTexture[SkyImageWidth][SkyImageHeight][3];
    int u, v , i = 0;

    // enable texture mapping
    glEnable(GL_TEXTURE_2D);

    // for each texture element
    for(u = 0; u < SkyImageWidth; u++)
    {
        for(v = 0; v < SkyImageHeight; v++)
        {
            // assign a random color, except for BLUE
            myTexture[u][v][0] =  imageDataOfSky[i];
            myTexture[u][v][1] =  imageDataOfSky[i + 1];
            myTexture[u][v][2] =  imageDataOfSky[i + 2];
            i += 3;
        }
    }

    // generate texture ID
    glGenTextures(1, &skyTextureID);

    // set the blue texture to be current
    glBindTexture(GL_TEXTURE_2D, skyTextureID);

    // tell openGL how to scale the texture image up if needed
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    // tell openGL how to scale the texture image down if needed
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);


    // build mipmaps for the current texture
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, SkyImageWidth, SkyImageHeight,
                      GL_RGB, GL_UNSIGNED_BYTE, myTexture);


    glDisable(GL_TEXTURE_2D);
}


/************************************************************************
 
 Function:        str2GLfloat
 
 Description:     string to GLfloat.
 
 *************************************************************************/

GLfloat str2GLfloat(string num){
    GLfloat res;
    stringstream stream(num);
    stream>>res;
    return res;
}

/************************************************************************
 
 Function:        str2Int
 
 Description:     string to int.
 
 *************************************************************************/

int str2Int(string num){
    int res;
    stringstream stream(num);
    stream>>res;
    return res;
}

/************************************************************************
 
 Function:        split
 
 Description:     split strings.
 
 *************************************************************************/
void split(const string& s , vector<string>& sv , const char delim = ' '){
    sv.clear();
    istringstream iss(s);
    string temp;
    
    while (getline(iss, temp , delim)) {
//        GLfloat temp2 = str2GLfloat(temp);
        if (temp.compare(" ") != 0) {
            sv.emplace_back(move(temp));
        }
       
    }
}



/************************************************************************
 
 Function:        cessnaDataInput
 
 Description:    Save every data from cessna into parameters
 
 *************************************************************************/

void cessnaDataInput(){
    
    /**** 更改 ****/
    ifstream iFile ("/Users/WillJia/Desktop/Computer graphics Projects/project/project/cessna.txt");
    // ifstream iFile ("cessna.txt");
    
    if (iFile.is_open())
    {
        string line;
        int verticesIndex = 0;
        int normalsIndex = 0;
        
        
        /*Read from the stream, one line at a time */
        while ( getline (iFile,line) )
        {
            
            /* Declare a string stream object for each line*/
            stringstream ss(line);
            string kind, data;
            
            /* read from the string stream into variables using the comma as a delimeter */
            getline(ss,kind,' ');
            getline(ss,data,'\n');
            
            vector<string> dataVector;
            split(data, dataVector);
            
            // save vertices
            if (kind.compare("v") == 0) {
                
                for (int i = 0; i < 3; i++) {
                    // convert
                    GLfloat temp = str2GLfloat(dataVector[i]);
                    cessna[verticesIndex][i] = temp;
                    
                }
                //                cout <<  " v : " << verticesIndex << " ";
                //                for (int i = 0; i < 3; i++) {
                //
                //                    // cout << cessna[verticesIndex][i] << " ";
                //                }
                //                cout << endl;
                verticesIndex++;
                
                // save normals
            }else if(kind.compare("n") == 0){
                for (int i = 0; i < 3; i++) {
                    // convert
                    GLfloat temp = str2GLfloat(dataVector[i]);
                    normals[normalsIndex][i] = temp;
                    
                }
                //                cout <<  " n : " << normalsIndex + verticesIndex<< " ";
                //                for (int i = 0; i < 3; i++) {
                //
                //                    // cout << normals[normalsIndex][i] << " ";
                //                }
                //                cout << endl;
                normalsIndex++;
            }else if (kind.compare("g") == 0){
                object.push_back(g);
            }else if (kind.compare("f") == 0){
                //                cout << "f : ";
                
                for (int i = 0; i < dataVector.size(); i+=2) {
                    int fIndex = atoi(dataVector[i].c_str());
                    //                    cout << "/" << fIndex;
                    f.push_back(fIndex);
                }
                
                //                cout << endl;
                ////
                //                for (auto s : f ) {
                //                    cout << "/" << s;
                //                }
                object.back().push_back(f);
                f.clear();
            }
            
            
            
        }// end while

        for (int i = 0; i < object.size() ; i++){
            polygonsNumOfPlane++;
            for (int j = 0 ; j < object[i].size(); j++) {
                facesNumOfPlane++;
                for (int k = 0; k < object[i][j].size(); k++) {
                    verticesNumOfPlane++;
                }

            }
        }
        
        /*close  files*/
        
        iFile.close();
    }else cout << "Unable to open input file";
}




/************************************************************************
 
 Function:        propellerDataInput
 
 Description:    Save every data from propeller.txt into parameters
 
 *************************************************************************/
void propellerDataInput(){
    
    
    cout << "***********************"<< endl;
    /**** 更改 ****/
    ifstream iFile ("/Users/WillJia/Desktop/Computer graphics Projects/project/project/propeller.txt");
    // ifstream iFile ("propeller.txt");
    
    if (iFile.is_open())
    {
        string line;
        
        /*Read from the stream, one line at a time */
        while ( getline (iFile,line) )
        {
            
            /* Declare a string stream object for each line*/
            stringstream ss(line);
            string kind, data;
            
            /* read from the string stream into variables using the comma as a delimeter */
            getline(ss,kind,' ');
            getline(ss,data,'\n');
            
            vector<string> dataVector;
            split(data, dataVector);
            
            // save vertices
            if (kind.compare("g") == 0){
                propellerObject.push_back(propellerG);
            }else if (kind.compare("f") == 0){
                
                for (int i = 0; i < dataVector.size(); i+=2) {
                    int fIndex = atoi(dataVector[i].c_str());
                    //                    cout << "/" << fIndex;
                    propellerF.push_back(fIndex);
                }
                
                //                cout << endl;
                ////
                //                for (auto s : f ) {
                //                    cout << "/" << s;
                //                }
                propellerObject.back().push_back(propellerF);
                propellerF.clear();
            }
            
            
            
        }// end while
        
        for (int i = 0; i < propellerObject.size() ; i++){
            polygonsNumOfProp++;
            for (int j = 0 ; j < propellerObject[i].size(); j++) {
                facesNumOfProp++;
                for (int k = 0; k < propellerObject[i][j].size(); k++) {
                    verticesNumOfProp++;
                }
//                cout << endl;
            }
//            cout << endl;
        }
        
        /*close  files*/
        
        iFile.close();
    }else cout << "Unable to open input file";

}


/************************************************************************
 
 Function:        positonChange
 
 Description:     According to key function to change all postion
 
 *************************************************************************/
void positonChange(){
    
    //Left right
    // left
    if (caPoMoveLeftRight == 1) {
        tiltMode = 0;
        if ( planeTiltAngle[0][0] < 45 ) {
            caPoMoveLeftRightRotateValue +=  caPoMoveLeftRightSpeed  * (abs(planeTiltAngle[0][0])/10 + 1)* 2;
            // for rate of tilt angle
            planeTiltAngle[0][0] = turningAngle;
        }// end if
        
    }else if (caPoMoveLeftRight == -1){
        tiltMode = 0;
        if ( planeTiltAngle[0][0] >-45 ) {
            caPoMoveLeftRightRotateValue -= caPoMoveLeftRightSpeed * (abs(planeTiltAngle[0][0])/10 + 1)*2;
             // for rate of tilt angle
           planeTiltAngle[0][0] = turningAngle;
        }// end if
    }
    
    if ( planeTiltAngle[0][0] <= 45 && planeTiltAngle[0][0] > 0 ) {
        caPoMoveLeftRightRotateValue +=  caPoMoveLeftRightSpeed * 10 * (abs(planeTiltAngle[0][0])/10 + 1)* 2;
    }else if ((planeTiltAngle[0][0] >= -45 && planeTiltAngle[0][0] < 0 )){
        caPoMoveLeftRightRotateValue -=  caPoMoveLeftRightSpeed * 10 * (abs(planeTiltAngle[0][0])/10 + 1)* 2;
    }// end else if
    
    if (caPoMoveLeftRightRotateValue > 360) {
        caPoMoveLeftRightRotateValue = 0;
    }
    
    planeTiltAngle[1][0] = caPoMoveLeftRightRotateValue ;
    if (messageLeftPrint) {
       cout << caPoMoveLeftRightRotateValue << endl;
    }
    
    // Up down
        
        
    if (caPoMoveUpDown == 1) {
        tiltMode = 2;
        
        if (planeTiltAngle[tiltMode][0] < 45 && planeTiltAngle[tiltMode][0] > -45) {
            planeTiltAngle[tiltMode][0] += planeTiltSpeed[0];
        }
        if (planeTiltAngle[tiltMode][0] < 0) {
            
            GLfloat up =  caPoMoveUpSpeed * -1 * sin( angleConst * planeTiltAngle[tiltMode][0]) * 50;
            
            planePostionTranslate[1] += up;
            cameraPosition[1] += up;
            eyePositon[1] += up;
        }else{
            GLfloat up =  caPoMoveUpSpeed  * sin( angleConst * planeTiltAngle[tiltMode][0]) * 50;
            planePostionTranslate[1] += up;
            cameraPosition[1] += up;
            eyePositon[1] += up;
        }
    }else if(caPoMoveUpDown == -1){
        tiltMode = 2;
        
        if (planeTiltAngle[tiltMode][0] < 45 && planeTiltAngle[tiltMode][0] > -45) {
            planeTiltAngle[tiltMode][0] -= planeTiltSpeed[0];
        }
        if (planeTiltAngle[tiltMode][0] > 0) {
            
            GLfloat down =  caPoMoveUpSpeed  * -1 *  sin( angleConst * planeTiltAngle[tiltMode][0]) * 50;
            planePostionTranslate[1] += down;
            cameraPosition[1] += down;
            eyePositon[1] += down;
        }else{
             GLfloat down =  caPoMoveUpSpeed  *  sin( angleConst * planeTiltAngle[tiltMode][0]) * 50;
            planePostionTranslate[1] += down;
            cameraPosition[1] += down;
            eyePositon[1] += down;
        }
    }
    
    if (caPoMoveUpDown == 0) {
            GLfloat remain = caPoMoveUpSpeed * -1 * sin( angleConst * planeTiltAngle[2][0])*50;
            planePostionTranslate[1] += remain;
            cameraPosition[1] += remain;
            eyePositon[1] += remain;
    }else if (caPoMoveUpDown == 1){
        if ((planeTiltAngle[2][0] > 1  && planeTiltAngle[2][0] < 90 )) {
            GLfloat remain = caPoMoveUpSpeed * -1 * sin( angleConst * planeTiltAngle[2][0])*100;
            planePostionTranslate[1] += remain;
            cameraPosition[1] += remain;
            eyePositon[1] += remain;
        }
    }else if (caPoMoveUpDown == -1){
        if ((planeTiltAngle[2][0] > -90  && planeTiltAngle[2][0] < -1 )) {
            GLfloat remain = caPoMoveUpSpeed * -1 * sin( angleConst * planeTiltAngle[2][0])*100;
            planePostionTranslate[1] += remain;
            cameraPosition[1] += remain;
            eyePositon[1] += remain;
        }
    }
    
    
    if (caPoMoveSpeedOn == 1 ) {
        gearOn = 0;
        if (messageLeftPrint) {
            cout << "Speed up";
        }
        
        caPoMoveSpeed += 0.0005;
        delta+= 0.5;
        
//        cout << caPoMoveSpeed << endl;
    }else if (caPoMoveSpeedOn == -1 ) {
        gearOn = 0;
        if (caPoMoveSpeed >= 0.0005) {
            caPoMoveSpeed -= 0.0005;
            delta-= 0.5;
          
        }
        if (caPoMoveSpeed < 0) {
            cout << "wrong";
        }
        
    }
//      cout << caPoMoveSpeed << endl;
//    cout << delta << endl;
    if (gearOn) {
            if (caPoMoveSpeed > gear[gearOn-1]) {
                delta-= 0.5;
                caPoMoveSpeed -= 0.01;
            }else if(caPoMoveSpeed < gear[gearOn-1]){
                delta+= 0.5;
                caPoMoveSpeed += 0.01;
            }
    }
    
     if (messageLeftPrint) cout << "caPoMoveSpeed " << caPoMoveSpeed << endl;
}



// Main functions to draw


/************************************************************************
 
 Function:        BallAtOriginalPoint
 
 Description:     Draw 3 lines that represents the positive unit vectors
 in the X, Y and Z directions, with line width = 5. Make the lines colored
 red, green and blue, respectively.
 
 *************************************************************************/

void BallAtOriginalPoint(){
    // sphere resolution
    int resolution = 20;
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    glLineWidth(1);
    
    
    GLfloat colorDiffuse[] = { 1 , 1 , 1, 1};
    glMaterialfv(GL_FRONT, GL_AMBIENT,   zeroMaterial);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   colorDiffuse); //whiteTranslucent);
    glMaterialfv(GL_FRONT, GL_SPECULAR,     whiteSpecular);
    glMaterialf(GL_FRONT,  GL_SHININESS, highShininess);
    glutSolidSphere(0.1 ,resolution,resolution);
    
}

/************************************************************************
 
 Function:        LinesAtOriginalPoint
 
 Description:     Draw 3 lines that represents the positive unit vectors
 in the X, Y and Z directions, with line width = 5. Make the lines colored
 red, green and blue, respectively.
 
 *************************************************************************/

void LinesAtOriginalPoint(){
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    glLineWidth(5);
    

    
    for (int i = 0; i < 3; i++) {
        glMaterialfv(GL_FRONT, GL_AMBIENT,   colors[i]);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   colors[i]); //whiteTranslucent);
        glMaterialfv(GL_FRONT, GL_SPECULAR,   whiteSpecular);
        glMaterialf(GL_FRONT,  GL_SHININESS, highShininess);
        
        glBegin(GL_LINES);
        glVertex3fv(linesAtOriginal[0]);
        glVertex3fv(linesAtOriginal[i+1]);
        glEnd();
    }
    
   BallAtOriginalPoint();
    
}



/************************************************************************
 
 Function:        GridConstruct
 
 Description:     Construct a grid of GL_QUADS on the X-Z plane centered
                  at the origin.
 
 *************************************************************************/

void GridConstruct(){
    // Fill Vertices
    // divide 4 parts
    int x = -gridSize/2,z = -gridSize/2;

        for (int j = 0 ; j <= gridSize; j++) {
            for (int k = 0; k <= gridSize; k++) {
                grid[j][k][0] = (k + x)*rate;
                grid[j][k][1] = -0.1 * rate ;
                grid[j][k][2] = (j + z)*rate;
            }// end k
        }// end j
    
    for (int j = 0 ; j <= gridSize; j++) {
        for (int k = 0; k <= gridSize; k++) {
            /*
            cout << grid[j][k][0] ;
            cout << grid[j][k][1] ;
            cout << grid[j][k][2] ;
            cout << " ";
             */
        }// end k
//        cout << endl;
    }// end j
    
}

/************************************************************************
 
 Function:        GridDraw
 
 Description:     Construct a grid of GL_QUADS on the X-Z plane centered
 at the origin.
 
 *************************************************************************/

void GridDraw(){
    

    if (moutainOn) {
        dividepolygon(polygon1[0] , polygon1[1] ,polygon1[2],polygon1[3] , RECURSIVE_LEVELS);
    }
    if (DiskOn == 0) {
        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {

                GLfloat colorDiffuse1[] =  {0.3215686275, 0.298039215686275, 0.462745098039216 , 1};
                glMaterialfv(GL_FRONT, GL_AMBIENT,   colorDiffuse1);
                glMaterialfv(GL_FRONT, GL_DIFFUSE,   colorDiffuse1); //whiteTranslucent);
                glMaterialfv(GL_FRONT, GL_SPECULAR,   whiteSpecular);
                glMaterialf(GL_FRONT,  GL_SHININESS, highShininess);

                glBegin(GL_QUADS);
                glVertex3fv(grid[i][j]);
                glVertex3fv(grid[i][j+1]);
                glVertex3fv(grid[i+1][j+1]);
                glVertex3fv(grid[i+1][j]);

                glEnd();

            }
        }
        
        
    }else{
        
//        glPolygonMode(GL_FRONT, GL_LINE);
//        glPolygonMode(GL_BACK, GL_LINE);
//
        
        // tell openGL how to scale the texture image up if needed
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        // tell openGL how to scale the texture image down if needed
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        
        GLUquadricObj* quadricPtr;
        quadricPtr = gluNewQuadric();
        
        if (frameOn ) {
            gluQuadricDrawStyle(quadricPtr, GLU_FILL);
        }else{
            gluQuadricDrawStyle(quadricPtr, GLU_LINE);
        }
        
      
        glShadeModel(GL_SMOOTH);
        gluQuadricNormals(quadricPtr, GLU_SMOOTH);
        gluQuadricTexture(quadricPtr, GL_TRUE);
        
        
        if (fogOn) {
            glEnable(GL_FOG);
            
            GLfloat fogColor[4] = {1, 1, 1, 0};
            glFogfv(GL_FOG_COLOR, fogColor);
            glFogf(GL_FOG_MODE, GL_EXP);
            glFogf(GL_FOG_DENSITY, 0.008);
            
        }
        
        // set the red texture to be current
        glPushMatrix();
        
        glEnable(GL_TEXTURE_2D);
        
       
        GLfloat emission[] = {1 , 1, 1, 0.4};
        GLfloat emission2[] = {0 , 0, 0, 0};
        glMaterialfv(GL_FRONT, GL_EMISSION, emission);
        
        glBindTexture(GL_TEXTURE_2D, seaTextureID);
        
        glRotated(90, 1, 0, 0);
        gluDisk(quadricPtr , 0,60 , 100 , 50);
        glDisable(GL_TEXTURE_2D);
        glPopMatrix();
        
     
        
       
      

        glPushMatrix();
        
        glEnable(GL_TEXTURE_2D);
        
        glMaterialfv(GL_FRONT, GL_EMISSION, emission);
        glBindTexture(GL_TEXTURE_2D, skyTextureID);
        
        glTranslated(0, -5, 0);
        glRotated(-90, 1, 0, 0);
        gluCylinder(quadricPtr , 50 , 50 , 50 , 200 , 50);
        glDisable(GL_TEXTURE_2D);
       
        glPopMatrix();
        glMaterialfv(GL_FRONT, GL_EMISSION, emission2);
        if (fogOn) {
            glDisable(GL_FOG);
        }
        gluDeleteQuadric(quadricPtr);
    }

  
}


/************************************************************************
 
 Function:        PlaneDraw
 
 Description:    Draw the cessna plane
 
 *************************************************************************/
void PlaneDraw(){
    
    
    
    
    // keep moving
  
    // for change

    int direction = 1;
    
    planePostionTranslate[0] -= direction * caPoMoveSpeed * sin(PI/2 + caPoMoveLeftRightRotateValue * angleConst);
    
    planePostionTranslate[2] -= direction * caPoMoveSpeed * cos(PI/2 + caPoMoveLeftRightRotateValue * angleConst) ;
    
    eyePositon[0] -= direction * caPoMoveSpeed * sin(PI/2 + caPoMoveLeftRightRotateValue * angleConst) ;
    
    eyePositon[2] -= direction * caPoMoveSpeed * cos(PI/2 + caPoMoveLeftRightRotateValue * angleConst) ;

    
//    for (int i = 0; i < object.size() ; i++){
    long gap = object.size();
    
    if (demoStart == 1) {
        gap = 1;
    }else{
         gap = object.size();
    }
      for (int i = demoTest; i < demoTest+gap ; i++){
        for (int j = 0 ; j < object[i].size(); j++) {
            // start draw polygon
            
            glPushMatrix();
            
            
            
            
            // for position change
            
            glTranslatef(planePostionTranslate[0], planePostionTranslate[1], planePostionTranslate[2]);
            
            glRotated(planePostionRoate[0],planePostionRoate[1], planePostionRoate[2], planePostionRoate[3]);
            
            
            glRotated(planeTiltAngle[1][0], planeTiltAngle[1][1]
                      , planeTiltAngle[1][2], planeTiltAngle[1][3]);
            
            for (int i = 0; i < 3; i+=2) {
                //                for (int i = 1; i < 3; i++) {
                glRotated(planeTiltAngle[i][0], planeTiltAngle[i][1]
                          , planeTiltAngle[i][2], planeTiltAngle[i][3]);
            }
            
            

            
            glMaterialfv(GL_FRONT, GL_AMBIENT,   cessnaColor[i]);
            glMaterialfv(GL_FRONT, GL_DIFFUSE,   cessnaColor[i]); //whiteTranslucent);
            glMaterialfv(GL_FRONT, GL_SPECULAR,   whiteSpecular);
            glMaterialf(GL_FRONT,  GL_SHININESS, PlaneShininess);
        
            // gl begin
            glBegin(GL_POLYGON);
            for (int k = 0; k < object[i][j].size(); k++) {
                
                // draw one polygon
                glNormal3fv(normals[-1 + object[i][j][k]]);
                glVertex3fv(cessna[-1 + object[i][j][k]]);
                
            }
            glEnd();
          
            glPopMatrix();
        }
    }
    
    
}


/************************************************************************
 
 Function:        propellerDraw
 
 Description:    Draw propeller
 
 *************************************************************************/
void propellerDraw(){
    
    for (int s = 0; s < 2; s++) {
    
        

        
        // Propeller rotating
     
        
        for (int i = 0; i < propellerObject.size() ; i++){
            
            for (int j = 0 ; j < propellerObject[i].size(); j++) {
                // start draw polygon
                
                glPushMatrix();
                
             
            
                
                // for position change
                
                glTranslatef(planePostionTranslate[0], planePostionTranslate[1], planePostionTranslate[2]);
                
                glRotated(planePostionRoate[0],planePostionRoate[1], planePostionRoate[2], planePostionRoate[3]);
                
                
                // plane tilt
                glRotated(planeTiltAngle[1][0], planeTiltAngle[1][1]
                          , planeTiltAngle[1][2], planeTiltAngle[1][3]);
                
                for (int i = 0; i < 3; i+=2) {
//                for (int i = 1; i < 3; i++) {
                    glRotated(planeTiltAngle[i][0], planeTiltAngle[i][1]
                              , planeTiltAngle[i][2], planeTiltAngle[i][3]);
                }
                
                
                // move to original
                
                // draw mirror propell
                if (s == 1) {
                    glScalef(1, 1, -1);
                }
                
                glTranslatef(0,-0.148 , 0.353);
                glRotated(-theta, 1, 0,0 );
                glTranslatef(0,+0.148 , -0.353);

                glMaterialfv(GL_FRONT, GL_AMBIENT,   propellColor[i]);
                glMaterialfv(GL_FRONT, GL_DIFFUSE,   propellColor[i]); //whiteTranslucent);
                glMaterialfv(GL_FRONT, GL_SPECULAR,   whiteSpecular);
                glMaterialf(GL_FRONT,  GL_SHININESS, highShininess);
          
                glBegin(GL_POLYGON);
            
                for (int k = 0; k < propellerObject[i][j].size(); k++) {
            
                    // draw one polygon
                     glNormal3fv(normals[-1 + propellerObject[i][j][k]]);
                    glVertex3fv(cessna[-1 + propellerObject[i][j][k]]);
                
                }
           
                glEnd();
               
                glPopMatrix();
               
            }
        }
        
    
    }// end for
    
}

/************************************************************************
 
 Function:        myDisplay
 
 Description:    Display callback, clears frame buffer and depth buffer,
 and draws the balls.
 
 *************************************************************************/
void myDisplay(void)
{
    
    // sphere resolution
    int resolution = 20;

    
//    if (smoothOn){
////        cout << "smoothOn " << smoothOn << endl;
        glShadeModel(GL_SMOOTH);
//    }else{
//        cout << "smoothOn " << smoothOn << endl;
//        glShadeModel(GL_FLAT);
//    }
    
    if (frameOn) {
        glPolygonMode(GL_FRONT, GL_FILL);
        glPolygonMode(GL_BACK, GL_FILL);
    }else{
        glPolygonMode(GL_FRONT, GL_LINE);
        glPolygonMode(GL_BACK, GL_LINE);
    }
    // clear the screen and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // load the identity matrix into the model view matrix
    glLoadIdentity();
    positonChange();
    
//    radius+= caPoMoveSpeed;
    if (messageLeftPrint){
    cout << "planeTiltAngle[2][0] " << planeTiltAngle[2][0] << endl;
    cout << "eyePostion[1]" << eyePositon[1] << endl;
    }
    double caLength = sqrt(pow(eyePositon[0] + radius * sin(PI/2 + caPoMoveLeftRightRotateValue * angleConst), 2) + pow(eyePositon[2] + radius * cos(PI/2 + caPoMoveLeftRightRotateValue * angleConst), 2));
    if (messageLeftPrint)
        cout << "ca length : " << caLength << endl;
    double eyeLength = sqrt(pow(eyePositon[0], 2) + pow(eyePositon[2], 2)) ;
    if (messageLeftPrint){
        cout << "eye length : " << eyeLength << endl;
       cout << "cameramove " << abs(caLength - eyeLength) * sin (planeTiltAngle[2][0] * angleConst ) << endl;
    }
    // set the camera position
    gluLookAt(
              eyePositon[0] + radius * sin(PI/2 + caPoMoveLeftRightRotateValue * angleConst), cameraPosition[1] ,  eyePositon[2] + radius * cos(PI/2 + caPoMoveLeftRightRotateValue * angleConst),
              
              eyePositon[0]  ,   eyePositon[1] ,  eyePositon[2],
              0,   1,    0);
    
   
    
    // position light 0
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    

    LinesAtOriginalPoint();
 
    GridDraw();
    
    PlaneDraw();
    if (messageLeftPrint) cout << "平飞 : " << planeTiltAngle[1][0]  << endl;
    propellerDraw();
    // swap the drawing buffers
    glutSwapBuffers();
}




/************************************************************************
 
 Function:        initializeGL
 
 Description:    Initializes the OpenGL rendering context for display.
 
 *************************************************************************/
void initializeGL(void)
{
    // define the light color and intensity
    GLfloat ambientLight[]    = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat diffuseLight[]    = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat specularLight[]    = { 1.0, 1.0, 1.0, 1.0 };
    
    //  the global ambient light level
    GLfloat globalAmbientLight[] = { 0.4, 0.4, 0.4, 1.0 };
    
    // set the global ambient light level
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbientLight);
    
    // define the color and intensity for light 0
    glLightfv(GL_LIGHT0, GL_AMBIENT,   ambientLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR,  diffuseLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,   specularLight);
    
    // enable lighting
    glEnable(GL_LIGHTING);
    // enable light 0
    glEnable(GL_LIGHT0);
    
    // */
    glEnable(GL_DEPTH_TEST);
    
    // make sure the normals are unit vectors
    glEnable(GL_NORMALIZE);
    
    glShadeModel(GL_SMOOTH);
    
//    // update the viewport to still be all of the window
//    glViewport (0, 0, windowWidth, windowHeight);
//
//    // change into projection mode so that we can change the camera properties
//    glMatrixMode(GL_PROJECTION);
//
//    // load the identity matrix into the projection matrix
//    glLoadIdentity();
//
//    // gluPerspective(fovy, aspect, near, far)
//    gluPerspective(45, (float)windowWidth/(float)windowHeight, 0.1, 300);
//
//    // change into model-view mode so that we can change the object positions
//    glMatrixMode(GL_MODELVIEW);
    
    
    
}
/************************************************************************
 
 Function:        myIdle
 
 Description:    Check things which need to update
 
 *************************************************************************/

void myIdle()
{
    if (theta <= 360 ) {
        if (delta > 30) {
            delta = 30;
        }
        if (delta < 0) {
            delta = 3;
        }
        theta+= delta;
    }else{
        theta = 0;
    }
//    cout << fullScreenOn << endl;
    if(fullScreenOn == 1){
        glutFullScreen();
    }else if(fullScreenOn == -1){
        glutReshapeWindow(OwindowWidth,OwindowHeight);
        glutPositionWindow(100, 100);
        fullScreenOn = 0;
    }
    // redraw the new state
    glutPostRedisplay();
}


/************************************************************************
 
 Function:        myResize
 
 Description:    Handles a user resize of the window.
 
 *************************************************************************/
void myResize(int newWidth, int newHeight)
{
    if (fullScreenOn != -1) {
        // update the new width
        windowWidth = newWidth;
        // update the new height
        windowHeight = newHeight;
    }
  
    
    // update the viewport to still be all of the window
    glViewport (0, 0, windowWidth, windowHeight);
    
    // change into projection mode so that we can change the camera properties
    glMatrixMode(GL_PROJECTION);
    
    // load the identity matrix into the projection matrix
    glLoadIdentity();
    
    // gluPerspective(fovy, aspect, near, far)
    gluPerspective(45, (float)windowWidth/(float)windowHeight, 0.1, 300);
    
    // change into model-view mode so that we can change the object positions
    glMatrixMode(GL_MODELVIEW);
}



/************************************************************************
 
 Function:        myKeys
 
 Description:    Handles keyboard input.
 
 *************************************************************************/
void myKeys(unsigned char key, int x, int y)
{
    if (key == '1') {
        gearOn = 1;
    }
    
    if (key == '2') {
        gearOn = 2;
    }
    if (key == '3') {
        gearOn = 3;
    }
    if (key == '4') {
        gearOn = 4;
    }
    
    if (key == 'm' || key == 'M') {
        moutainOn = !moutainOn;
    }
    
    if ((key == 'w') || (key == 'W'))
        frameOn = !frameOn;
    
    if (key == 'l')
        smoothOn = !smoothOn;
    
    if ((key == 'q') || (key == 'Q'))
        exit(0);
    
    if ((key == 'f') || (key == 'F')){
        if (fullScreenOn == 0 || fullScreenOn == -1) {
            fullScreenOn = 1;
        }else if(fullScreenOn == 1){
            fullScreenOn = -1;
        }
    }

    if (key == 'i') {
        if (demoTest < 33) {
            demoTest++;
//            cout << demoTest << endl;
        }
        
    }else if (key == 'I'){
        if (demoTest > 0) {
            demoTest--;
//            cout << demoTest << endl;
        }
        
    }
    if (key == ']') {
        if (demoStart == 0) {
            demoStart = 1;
        }else{
            demoStart = 0;
            demoTest = 0;
        }
    }
    
    if (key == 's' || key == 'S') {
        if (DiskOn == 0) {
            DiskOn = 1;
        }else{
            DiskOn = 0;
        }
    }
    
    
    
    if (key == 'b' || key == 'B') {
         fogOn = !fogOn;
    }
    glutPostRedisplay();
}

/************************************************************************
 
 Function:        myMouse
 
 Description:    change turning speed
 
 *************************************************************************/

void myMouseMove( int x, int y)
{
   
    
    GLfloat decideLength = windowWidth / 2.0;
    if (x - decideLength > 0) {
        caPoMoveLeftRight = -1;
    } else {
        caPoMoveLeftRight = 1;
    }
    GLfloat rotaingAngle = (x - decideLength) * -1.0 / decideLength * 45;
    if(x > decideLength - 10 && x < decideLength + 10){
        turningAngle = 0;
    }else{
        if (rotaingAngle >= -45 &&  rotaingAngle <= 45) {
            turningAngle = rotaingAngle;
        }
        
    }
    
    if (messagePrint) {
        cout << "xxxxx = " << x << endl;
        cout << "yyyyy = " << y << endl;
        cout << "turing angle = " << turningAngle << endl;
    }
    
    glutPostRedisplay();
}



/************************************************************************
 
 Function:        specialKeys
 
 Description:    Print out control information.
 
 *************************************************************************/
void specialKeys(int key, int x, int y){
    
    if (key == GLUT_KEY_PAGE_UP ) {
//        cout << "sdf" ;
        caPoMoveSpeedOn = 1;
    }
    if (key == GLUT_KEY_PAGE_DOWN ) {
        caPoMoveSpeedOn = -1;
    }
    if (key == GLUT_KEY_UP) {
        caPoMoveUpDown = 1;
    }
    if (key == GLUT_KEY_DOWN) {
        caPoMoveUpDown = -1;
    }
    
    if (key == GLUT_KEY_LEFT) {
        caPoMoveLeftRight = 1;
        
    }
        
    if (key == GLUT_KEY_RIGHT) {
        caPoMoveLeftRight = -1;
    }
        
}
/************************************************************************
 
 Function:        specialKeysUp
 
 Description:    change state
 
 *************************************************************************/

void specialKeysUp(int key, int x, int y){
    

    if (key == GLUT_KEY_UP) {
        caPoMoveUpDown = 0;
    }
    if (key == GLUT_KEY_DOWN) {
        caPoMoveUpDown = 0;
    }
    if (key == GLUT_KEY_PAGE_UP ) {
        caPoMoveSpeedOn = 0;
    }
    if (key == GLUT_KEY_PAGE_DOWN ) {
        caPoMoveSpeedOn = 0;
    }
    if (key == GLUT_KEY_LEFT) {
        caPoMoveLeftRight = 0;
        
    }
    
    if (key == GLUT_KEY_RIGHT) {
        caPoMoveLeftRight = 0;
    }
    
    glutPostRedisplay();
    
}


/************************************************************************
 
 Function:        printControlInfo
 
 Description:    Print out control information.
 
 *************************************************************************/
void printControlInfo()
{
    printf("\n\n\n");
    printf(" Scene Controls\n");
    printf(" -----------------\n");
    printf(" s   : toggle sky and sea\n");
    printf(" f   : toggle fullscreen\n");
    printf(" b   : toggle fog\n");
    printf(" w   : toggle wire frame\n");
    printf(" m   : toggle mountains\n");
    printf(" q   : quit\n");
    printf("\n");
    printf("Camera Controls\n");
    printf(" -----------------\n");
    printf("    '1'    :   Gear 1 speed\n");
    printf("    '2'    :   Gear 2 speed\n");
    printf("    '3'    :   Gear 3 speed\n");
    printf("    '4'    :   Gear 4 speed\n");
    printf("Page up    :   faster\n");
    printf("Page down  :   slower\n");
    printf("Up   Arrow :   move up\n");
    printf("Down Arrow :   move down\n");
    printf("Mouse Right:   move right\n");
    printf("Mouse left :   move left\n");
    printf("\n");
    cout << "Number of vertices used on (plane)  " << verticesNumOfPlane << endl;
    cout << "Number of faces on used on (plane)  " << facesNumOfPlane << endl;
    cout << "Number of polygons used on (plane)  " << polygonsNumOfPlane << endl;
    cout << "Number of vertices used on (prop)  " << verticesNumOfProp * 2<< endl;
    cout << "Number of faces on used on (prop)  " << facesNumOfProp * 2<< endl;
    cout << "Number of polygons used on (prop)  " << polygonsNumOfProp * 2 << endl;
    
    
}


/************************************************************************
 
 Function:        main
 
 Description:    Sets up the openGL rendering context and the windowing
 system, then begins the display loop.
 
 *************************************************************************/
int main(int argc, char** argv)
{
 
    // initialize the toolkit
    glutInit(&argc, argv);
    // set display mode
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    // set window size
    glutInitWindowSize(windowWidth, windowHeight);
    // set window position on screen
    glutInitWindowPosition(100, 100);
    // open the screen window
    glutCreateWindow("Project");
    
    // register redraw function
    glutDisplayFunc(myDisplay);
    // register special keyboard handler
    glutSpecialFunc(specialKeys);
    // register special keyboard handler
    glutSpecialUpFunc(specialKeysUp);
    // register keyboard handler
    glutKeyboardFunc(myKeys);
  
    // register mouse handler
    glutPassiveMotionFunc( myMouseMove);
    // register the resize function
    glutReshapeFunc(myResize);
    // register the idle function
    glutIdleFunc(myIdle);
    // print out control info

   
   
    //initialize the rendering context
    initializeGL();
    
    loadImage("/Users/WillJia/Desktop/Computer graphics Projects/project/project/pic123.ppm" , imageDataOfSea, &SeaImageWidth , &SeaImageHeight);
    
    loadImage("/Users/WillJia/Desktop/Computer graphics Projects/project/project/sky008.ppm" , imageDataOfSky, &SkyImageWidth , &SkyImageHeight);
    
    cout << SeaImageHeight << SeaImageHeight << endl;
//    loadImage("/Users/WillJia/Desktop/Computer graphics Projects/Earth/Earth/sky08.bmp" , imageDataOfSky);
    
    createSeaTexture();
    createSkyTexture();
    GridConstruct();
    cessnaDataInput();
    propellerDataInput();
    printControlInfo();
    // go into a perpetual loop
    glutMainLoop();
}


