#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cmath>
#include <cstdlib>

namespace
{
constexpr float kPi = 3.14159265f;

float cameraAngleY = 20.0f;
float cameraHeight = 8.0f;
float zoomDistance = 28.0f;
float targetX = 0.0f;
float targetY = 3.5f;
}

void setColor(float r, float g, float b)
{
    glColor3f(r, g, b);
}

void drawCube(float width, float height, float depth, float r, float g, float b)
{
    glPushMatrix();
    glScalef(width, height, depth);
    setColor(r, g, b);
    glutSolidCube(1.0f);
    glPopMatrix();
}

void drawFloor()
{
    setColor(0.72f, 0.60f, 0.44f);
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-14.0f, 0.0f, -14.0f);
    glVertex3f(14.0f, 0.0f, -14.0f);
    glVertex3f(14.0f, 0.0f, 14.0f);
    glVertex3f(-14.0f, 0.0f, 14.0f);
    glEnd();

    setColor(0.54f, 0.44f, 0.31f);
    glBegin(GL_LINES);
    for (float x = -14.0f; x <= 14.01f; x += 2.0f)
    {
        glVertex3f(x, 0.01f, -14.0f);
        glVertex3f(x, 0.01f, 14.0f);
    }
    for (float z = -14.0f; z <= 14.01f; z += 2.0f)
    {
        glVertex3f(-14.0f, 0.01f, z);
        glVertex3f(14.0f, 0.01f, z);
    }
    glEnd();
}

void drawCeiling()
{
    setColor(0.95f, 0.95f, 0.92f);
    glBegin(GL_QUADS);
    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(-14.0f, 12.0f, -14.0f);
    glVertex3f(-14.0f, 12.0f, 14.0f);
    glVertex3f(14.0f, 12.0f, 14.0f);
    glVertex3f(14.0f, 12.0f, -14.0f);
    glEnd();
}

void drawWalls()
{
    setColor(0.89f, 0.92f, 0.94f);
    glBegin(GL_QUADS);

    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-14.0f, 0.0f, -14.0f);
    glVertex3f(-14.0f, 12.0f, -14.0f);
    glVertex3f(14.0f, 12.0f, -14.0f);
    glVertex3f(14.0f, 0.0f, -14.0f);

    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-14.0f, 0.0f, 14.0f);
    glVertex3f(-14.0f, 12.0f, 14.0f);
    glVertex3f(-14.0f, 12.0f, -14.0f);
    glVertex3f(-14.0f, 0.0f, -14.0f);

    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(14.0f, 0.0f, -14.0f);
    glVertex3f(14.0f, 12.0f, -14.0f);
    glVertex3f(14.0f, 12.0f, 14.0f);
    glVertex3f(14.0f, 0.0f, 14.0f);

    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(-14.0f, 0.0f, 14.0f);
    glVertex3f(14.0f, 0.0f, 14.0f);
    glVertex3f(14.0f, 12.0f, 14.0f);
    glVertex3f(-14.0f, 12.0f, 14.0f);

    glEnd();

    setColor(0.72f, 0.78f, 0.83f);
    glBegin(GL_QUADS);
    glVertex3f(-14.0f, 0.0f, -13.95f);
    glVertex3f(14.0f, 0.0f, -13.95f);
    glVertex3f(14.0f, 1.6f, -13.95f);
    glVertex3f(-14.0f, 1.6f, -13.95f);

    glVertex3f(-13.95f, 0.0f, -14.0f);
    glVertex3f(-13.95f, 1.6f, -14.0f);
    glVertex3f(-13.95f, 1.6f, 14.0f);
    glVertex3f(-13.95f, 0.0f, 14.0f);

    glVertex3f(13.95f, 0.0f, -14.0f);
    glVertex3f(13.95f, 1.6f, -14.0f);
    glVertex3f(13.95f, 1.6f, 14.0f);
    glVertex3f(13.95f, 0.0f, 14.0f);
    glEnd();
}

void drawFrontPlatform()
{
    glPushMatrix();
    glTranslatef(0.0f, 0.35f, -10.2f);
    drawCube(12.5f, 0.7f, 5.2f, 0.59f, 0.45f, 0.30f);
    glPopMatrix();
}

void drawBoard()
{
    glPushMatrix();
    glTranslatef(0.0f, 6.1f, -13.35f);
    drawCube(10.4f, 4.0f, 0.2f, 0.02f, 0.02f, 0.02f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 6.1f, -13.28f);
    drawCube(10.9f, 4.4f, 0.16f, 0.52f, 0.33f, 0.12f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 3.8f, -13.2f);
    drawCube(9.2f, 0.16f, 0.45f, 0.46f, 0.30f, 0.12f);
    glPopMatrix();

    setColor(0.92f, 0.95f, 0.92f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex3f(-3.6f, 7.0f, -13.23f);
    glVertex3f(3.4f, 7.0f, -13.23f);
    glVertex3f(-2.8f, 6.2f, -13.23f);
    glVertex3f(2.8f, 6.2f, -13.23f);
    glVertex3f(-1.6f, 5.4f, -13.23f);
    glVertex3f(1.8f, 5.4f, -13.23f);
    glEnd();
    glLineWidth(1.0f);
}

void drawWindow(float x)
{
    glPushMatrix();
    glTranslatef(x, 6.5f, 13.25f);
    drawCube(3.4f, 3.2f, 0.15f, 0.60f, 0.83f, 0.96f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x, 6.5f, 13.18f);
    drawCube(3.8f, 3.6f, 0.12f, 0.45f, 0.28f, 0.12f);
    glPopMatrix();

    setColor(0.34f, 0.22f, 0.09f);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glVertex3f(x - 1.7f, 6.5f, 13.31f);
    glVertex3f(x + 1.7f, 6.5f, 13.31f);
    glVertex3f(x, 4.9f, 13.31f);
    glVertex3f(x, 8.1f, 13.31f);
    glEnd();
    glLineWidth(1.0f);
}

void drawDoor()
{
    glPushMatrix();
    glTranslatef(13.1f, 4.0f, 9.5f);
    drawCube(0.3f, 8.0f, 3.2f, 0.42f, 0.24f, 0.10f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(13.15f, 4.0f, 9.5f);
    drawCube(0.12f, 8.3f, 3.5f, 0.28f, 0.16f, 0.06f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(12.95f, 4.0f, 10.6f);
    drawCube(0.18f, 0.18f, 0.18f, 0.88f, 0.72f, 0.25f);
    glPopMatrix();
}

void drawLeg(float x, float y, float z)
{
    glPushMatrix();
    glTranslatef(x, y, z);
    drawCube(0.18f, 1.4f, 0.18f, 0.02f, 0.02f, 0.02f);
    glPopMatrix();
}

void drawDesk()
{
    glPushMatrix();
    glTranslatef(0.0f, 1.55f, 0.0f);
    drawCube(2.4f, 0.18f, 1.5f, 0.94f, 0.94f, 0.90f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 1.18f, -0.56f);
    drawCube(2.1f, 0.7f, 0.12f, 0.02f, 0.02f, 0.02f);
    glPopMatrix();

    drawLeg(-0.98f, 0.7f, -0.58f);
    drawLeg(0.98f, 0.7f, -0.58f);
    drawLeg(-0.98f, 0.7f, 0.58f);
    drawLeg(0.98f, 0.7f, 0.58f);
}

void drawChair()
{
    glPushMatrix();
    glTranslatef(0.0f, 1.0f, 0.0f);
    drawCube(1.0f, 0.14f, 1.0f, 0.94f, 0.94f, 0.90f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 1.86f, -0.42f);
    drawCube(1.0f, 1.45f, 0.12f, 0.02f, 0.02f, 0.02f);
    glPopMatrix();

    drawLeg(-0.4f, 0.5f, -0.4f);
    drawLeg(0.4f, 0.5f, -0.4f);
    drawLeg(-0.4f, 0.5f, 0.4f);
    drawLeg(0.4f, 0.5f, 0.4f);
}

void drawStudentSet(float x, float z)
{
    glPushMatrix();
    glTranslatef(x, 0.0f, z);
    drawDesk();
    glTranslatef(0.0f, 0.0f, 1.75f);
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    drawChair();
    glPopMatrix();
}

void drawClock()
{
    glPushMatrix();
    glTranslatef(0.0f, 9.5f, -13.25f);
    setColor(0.96f, 0.96f, 0.94f);
    glutSolidSphere(0.8f, 30, 30);
    glPopMatrix();

    setColor(0.15f, 0.15f, 0.15f);
    glLineWidth(2.5f);
    glBegin(GL_LINES);
    glVertex3f(0.0f, 9.5f, -12.42f);
    glVertex3f(0.0f, 9.9f, -12.42f);
    glVertex3f(0.0f, 9.5f, -12.42f);
    glVertex3f(0.32f, 9.36f, -12.42f);
    glEnd();
    glLineWidth(1.0f);
}

void drawTubeLight(float x, float z)
{
    glPushMatrix();
    glTranslatef(x, 11.45f, z);
    drawCube(3.5f, 0.12f, 0.4f, 0.96f, 0.96f, 0.88f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x, 11.25f, z);
    drawCube(3.8f, 0.08f, 0.55f, 0.70f, 0.70f, 0.68f);
    glPopMatrix();
}

void setupLighting()
{
    const GLfloat lightPosition[] = {0.0f, 10.8f, 2.0f, 1.0f};
    const GLfloat lightDiffuse[] = {0.92f, 0.92f, 0.88f, 1.0f};
    const GLfloat lightAmbient[] = {0.28f, 0.28f, 0.30f, 1.0f};
    const GLfloat lightSpecular[] = {0.35f, 0.35f, 0.35f, 1.0f};

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);

    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    const float angleRadians = cameraAngleY * kPi / 180.0f;
    const float eyeX = targetX + zoomDistance * std::sin(angleRadians);
    const float eyeZ = zoomDistance * std::cos(angleRadians);
    gluLookAt(eyeX, cameraHeight, eyeZ, targetX, targetY, 0.0f, 0.0f, 1.0f, 0.0f);

    drawFloor();
    drawCeiling();
    drawWalls();
    drawFrontPlatform();
    drawBoard();
    drawClock();
    drawWindow(-7.0f);
    drawWindow(0.0f);
    drawWindow(7.0f);
    drawDoor();
    drawTubeLight(-5.0f, -2.5f);
    drawTubeLight(5.0f, -2.5f);
    drawTubeLight(0.0f, 5.2f);

    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            const float x = -7.0f + static_cast<float>(col) * 7.0f;
            const float z = -1.6f + static_cast<float>(row) * 5.0f;
            drawStudentSet(x, z);
        }
    }

    glutSwapBuffers();
}

void reshape(int width, int height)
{
    if (height == 0)
    {
        height = 1;
    }

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, static_cast<double>(width) / static_cast<double>(height), 1.0, 100.0);
}

void keyboard(unsigned char key, int, int)
{
    switch (key)
    {
    case 'a':
    case 'A':
        cameraAngleY -= 5.0f;
        break;
    case 'd':
    case 'D':
        cameraAngleY += 5.0f;
        break;
    case 'w':
    case 'W':
        zoomDistance -= 1.0f;
        if (zoomDistance < 12.0f)
        {
            zoomDistance = 12.0f;
        }
        break;
    case 's':
    case 'S':
        zoomDistance += 1.0f;
        if (zoomDistance > 40.0f)
        {
            zoomDistance = 40.0f;
        }
        break;
    case 'j':
    case 'J':
        targetX -= 0.8f;
        if (targetX < -6.0f)
        {
            targetX = -6.0f;
        }
        break;
    case 'l':
    case 'L':
        targetX += 0.8f;
        if (targetX > 6.0f)
        {
            targetX = 6.0f;
        }
        break;
    case 'i':
    case 'I':
        targetY += 0.4f;
        if (targetY > 7.0f)
        {
            targetY = 7.0f;
        }
        break;
    case 'k':
    case 'K':
        targetY -= 0.4f;
        if (targetY < 1.5f)
        {
            targetY = 1.5f;
        }
        break;
    case 'r':
    case 'R':
        cameraAngleY = 20.0f;
        cameraHeight = 8.0f;
        zoomDistance = 28.0f;
        targetX = 0.0f;
        targetY = 3.5f;
        break;
    case 27:
        std::exit(0);
        break;
    default:
        break;
    }

    glutPostRedisplay();
}

void specialKeys(int key, int, int)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        cameraHeight += 1.0f;
        if (cameraHeight > 18.0f)
        {
            cameraHeight = 18.0f;
        }
        break;
    case GLUT_KEY_DOWN:
        cameraHeight -= 1.0f;
        if (cameraHeight < 4.0f)
        {
            cameraHeight = 4.0f;
        }
        break;
    case GLUT_KEY_LEFT:
        cameraAngleY -= 4.0f;
        break;
    case GLUT_KEY_RIGHT:
        cameraAngleY += 4.0f;
        break;
    default:
        break;
    }

    glutPostRedisplay();
}

void init()
{
    glClearColor(0.73f, 0.86f, 0.97f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LINE_SMOOTH);
    setupLighting();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1100, 700);
    glutCreateWindow("Improved OpenGL Classroom");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);

    glutMainLoop();
    return 0;
}
