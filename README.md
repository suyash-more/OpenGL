## OpenGL
- Open Graphics Library (OpenGL) is a cross-language (language independent), cross-platform (platform-independent) API for rendering 2D and 3D Vector Graphics(use of polygons to represent image). 
- This Repo Contains various codes related to the operations performed using OpenGL Library

####    This is the command for running the C/C++ Files
> Command
```sh
 g++ {CFileName}.c -lglut -lGL -lGLEW -lGLU -o {OutputFileName}
 g++ {CFileName}.cpp -lglut -lGL -lGLEW -lGLU -o {OutputFileName}
```

Table : 

|         Assignment Name         	|                                       Link                                      	|
|:-------------------------------:	|:-------------------------------------------------------------------------------:	|
|      Assign2-DDA-Bresenham      	|      https://github.com/suyash-more/OpenGL/tree/main/Assign2-DDA-Bresenham      	|
| Assign3-circleDrawing-Bresenham 	| https://github.com/suyash-more/OpenGL/tree/main/Assign3-circleDrawing-Bresenham 	|
|      Assign4-PolygonFilling     	|      https://github.com/suyash-more/OpenGL/tree/main/Assign4-PolygonFilling     	|
|     Assign5-PolygonClipping     	|     https://github.com/suyash-more/OpenGL/tree/main/Assign5-PolygonClipping     	|
|    Assign6-2dTransformations    	|    https://github.com/suyash-more/OpenGL/tree/main/Assign6-2dTransformations    	|
|      Assign7-fractalCurves      	|      https://github.com/suyash-more/OpenGL/tree/main/Assign7-fractalCurves      	|
|        Assign8-animation        	|        https://github.com/suyash-more/OpenGL/tree/main/Assign8-animation        	|
|             LabCode             	|             https://github.com/suyash-more/OpenGL/tree/main/LabCode             	|




GL - Graphics Library
> Headers freeglut.h, gl.h are there in GL which include all the necessary function like glutInit, glutInitDisplayMode etc


>glutInit(&argc, argv)
>> argc
>> - A pointer to the program's unmodified argc variable from main. Upon return, the value pointed to by argcp will be updated, because glutInit extracts any command line options intended for the GLUT library.

>>argv
>> - The program's unmodified argv variable from main. Like argcp, the data for argv will be updated because glutInit extracts any command line options understood by the GLUT library.


>glutInitDisplayMode(GLUT_SINGLE);
>>glutInitDisplayMode sets the initial display mode.
>> - The initial display mode is used when creating top-level windows, subwindows, and overlays to determine the OpenGL display mode for the to-be-created window or overlay.

>glutInitWindowSize(500,500);
>glutInitWindowPosition(500,500);
>>glutInitWindowPosition and   glutInitWindowSize set the initial window position and size respectively.
>> - Windows created by glutCreateWindow will be requested to be created with the current initial window position and size.


>glutCreateWindow("OpenGL - First window demo");
>>glutCreateWindow creates a top-level window.
>> - glutCreateWindow creates a top-level window. The name will be provided to the window system as the window's name. The intent is that the window system will label the window with the name.

>glutDisplayFunc(renderFunction);
>>glutDisplayFunc sets the display callback for the current window.
>> - glutDisplayFunc sets the display callback for the current window. When GLUT determines that the normal plane for the window needs to be redisplayed, the display callback for the window is called.

>glutMainLoop();
>> glutMainLoop enters the GLUT event processing loop.
>> - glutMainLoop enters the GLUT event processing loop. This routine should be called at most once in a GLUT program. Once called, this routine will never return. It will call as necessary any callbacks that have been registered.

>glClearColor(0.0, 0.0, 0.0, 0.0);
>>specify clear values for the color buffers
>> - glClearColor specifies the red, green, blue, and alpha values used by glClear to clear the color buffers. Values specified by glClearColor are clamped to the range [0,1].

>glClear(GL_COLOR_BUFFER_BIT);
>>clear buffers to preset values
>> - glClear sets the bitplane area of the window to values previously selected by glClearColor, glClearDepth, and glClearStencil. Multiple color buffers can be cleared simultaneously by selecting more than one buffer at a time using glDrawBuffer.

>glColor3f(1.0, 1.0, 1.0);
>> set the current color
>> - The GL stores both a current single-valued color index and a current four-valued RGBA color. glColor sets a new four-valued RGBA color. glColor has two major variants: glColor3 and glColor4. glColor3 variants specify new red, green, and blue values explicitly and set the current alpha value to 1.0 (full intensity) implicitly. glColor4 variants specify all four color components explicitly.

>glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
>>multiply the current matrix with an orthographic matrix
>> - glOrtho describes a transformation that produces a parallel projection.

>glBegin(GL_POLYGON);
>glEnd();
>>delimit the vertices of a primitive or a group of like primitives
>> - glBegin and glEnd delimit the vertices that define a primitive or a group of like primitives. glBegin accepts a single argument that specifies in which of ten ways the vertices are interpreted. Taking n as an integer count starting at one, and N as the total number of vertices specified

>glVertex2f(-0.5, -0.5);
>>specify a vertex
>> - glVertex commands are used within glBegin/glEnd pairs to specify point, line, and polygon vertices.

>glPointSize(1.0f);
>> If you want thinner or thicker line you can put the magnitude in there

>GLUT_RIGHT_BUTTON
>> Tells you the activity of right button

>GLUT_LEFT_BUTTON
>> Tells you the activity of left button

>GLUT_DOWN
>> returns true when the button is pressed