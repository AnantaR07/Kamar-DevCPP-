#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#include <iostream> 

bool isFirstMouse = true;
int lastX = -1;
int lastY = -1;
float mouseSensitivity = -0.1f;  // Ubah nilai ini untuk mengatur kecepatan1152, 680
int windowWidth = 1152;
int windowHeight = 680;
float angleX = 0.0f;
float angleY = 0.0f;
bool lightOn = true;

void mouseMotion(int x, int y) {
    if (isFirstMouse) {
        lastX = x;
        lastY = y;
        isFirstMouse = false;
    }

    int deltaX = x - lastX;
    int deltaY = y - lastY;

    angleY += deltaX * mouseSensitivity;
    angleX += deltaY * mouseSensitivity;

    // Batasi pitch untuk mencegah "over-rotation"
    if (angleX > 89.0f)
        angleX = 89.0f;
    if (angleX < -89.0f)
        angleX = -89.0f;

    lastX = x;
    lastY = y;
    glutWarpPointer(windowWidth / 2, windowHeight / 2);

    glutPostRedisplay();
}

void drawTexturedCube(float size) {
   float halfSize = size / 2.0;

   glBegin(GL_QUADS);

   // Front face
   glTexCoord2f(0.0, 0.0); glVertex3f(-halfSize, -halfSize, halfSize);
   glTexCoord2f(1.0, 0.0); glVertex3f(halfSize, -halfSize, halfSize);
   glTexCoord2f(1.0, 1.0); glVertex3f(halfSize, halfSize, halfSize);
   glTexCoord2f(0.0, 1.0); glVertex3f(-halfSize, halfSize, halfSize);

   // Back face
   glTexCoord2f(0.0, 0.0); glVertex3f(-halfSize, -halfSize, -halfSize);
   glTexCoord2f(1.0, 0.0); glVertex3f(halfSize, -halfSize, -halfSize);
   glTexCoord2f(1.0, 1.0); glVertex3f(halfSize, halfSize, -halfSize);
   glTexCoord2f(0.0, 1.0); glVertex3f(-halfSize, halfSize, -halfSize);

   // Top face
   glTexCoord2f(0.0, 0.0); glVertex3f(-halfSize, halfSize, halfSize);
   glTexCoord2f(1.0, 0.0); glVertex3f(halfSize, halfSize, halfSize);
   glTexCoord2f(1.0, 1.0); glVertex3f(halfSize, halfSize, -halfSize);
   glTexCoord2f(0.0, 1.0); glVertex3f(-halfSize, halfSize, -halfSize);

   // Bottom face
   glTexCoord2f(0.0, 0.0); glVertex3f(-halfSize, -halfSize, halfSize);
   glTexCoord2f(1.0, 0.0); glVertex3f(halfSize, -halfSize, halfSize);
   glTexCoord2f(1.0, 1.0); glVertex3f(halfSize, -halfSize, -halfSize);
   glTexCoord2f(0.0, 1.0); glVertex3f(-halfSize, -halfSize, -halfSize);

   // Right face
   glTexCoord2f(0.0, 0.0); glVertex3f(halfSize, -halfSize, halfSize);
   glTexCoord2f(1.0, 0.0); glVertex3f(halfSize, -halfSize, -halfSize);
   glTexCoord2f(1.0, 1.0); glVertex3f(halfSize, halfSize, -halfSize);
   glTexCoord2f(0.0, 1.0); glVertex3f(halfSize, halfSize, halfSize);

   // Left face
   glTexCoord2f(0.0, 0.0); glVertex3f(-halfSize, -halfSize, halfSize);
   glTexCoord2f(1.0, 0.0); glVertex3f(-halfSize, -halfSize, -halfSize);
   glTexCoord2f(1.0, 1.0); glVertex3f(-halfSize, halfSize, -halfSize);
   glTexCoord2f(0.0, 1.0); glVertex3f(-halfSize, halfSize, halfSize);

   glEnd();
}
void drawTexturedCube(float size);

GLuint loadTexture(const char *filename) {
    int width, height, nrChannels;
    unsigned char *data = stbi_load(filename, &width, &height, &nrChannels, 0);
    if (!data) {
        std::cerr << "Failed to load texture: " << filename << std::endl;
        return 0;
    }

    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, nrChannels == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    stbi_image_free(data);

    return textureID;
}

GLuint textureKayuCoklat;
GLuint textureKayuPutih;
GLuint textureSelimut;
GLuint textureKasur;
GLuint textureBantal;
GLuint textureKeramik;
GLuint textureKarpetMerah;
GLuint textureKarpetPutih;
GLuint textureTembok;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DEKLARASI DAN INISIASI VARIABEL ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DEKLARASI DAN INISIASI FUNGSI ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//****************************************** fungsi display **********************************************************************
void ubin(){
	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureKeramik);
    glColor3d(0.66,0.66,0.66);
    glPushMatrix();
        glTranslated(0.0,-14.0,-20.0);
        glScaled(12.0,0.2,10.0);
        drawTexturedCube(10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}
void jendela(){
    glColor3d(0.85,0.99,0.99);
    glutSolidCube(10);

    glColor3d(0.88,0.72,0.53);
    glPushMatrix();
        glTranslated(0.0,0.0,4.5);
        glScaled(4.0,1.0,0.1);
        glutSolidCube(10);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0.0,0.0,-4.5);
        glScaled(4.0,1.0,0.1);
        glutSolidCube(10);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0.0,4.5,0.0);
        glRotated(90.0,1.0,0.0,0.0);
        glScaled(4.0,1.0,0.1);
        glutSolidCube(10);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0.0,-4.5,0.0);
        glRotated(90.0,1.0,0.0,0.0);
        glScaled(4.0,1.0,0.1);
        glutSolidCube(10);
    glPopMatrix();
}

void dindingKanan(){
	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureTembok);
    glPushMatrix();
        glTranslated(61.0, 25.0, -20.0);
        glScaled(0.2, 8.0, 10.0); 
        glColor3d(0.75, 0.75, 0.75);
        drawTexturedCube(10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}
void dindingBelakang(){
    // dinding
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureTembok);
    glPushMatrix();
        glTranslated(0.0,25.0,-71.0);
        glScaled(12.0,8.0,0.2);
        drawTexturedCube(10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}
void dindingKiri(){
    //disamping
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureTembok);
    glPushMatrix();
        glTranslated(-51.0,25.0,-52.5);
        glScaled(0.2,8.0,3.5);
        drawTexturedCube(10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureTembok);
    glPushMatrix();
        glTranslated(-51.0,25.0,12.5);
        glScaled(0.2,8.0,3.5);
        drawTexturedCube(10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    //^^^^^^^^^^^^ 2 or center ^^^^^^^^^^^^^^^
    //atas
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureTembok);
    glPushMatrix();
        glTranslated(-51.0,55.0,-20.0);
        glScaled(0.2,2.0,3.0);
        drawTexturedCube(10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //bawah
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureTembok);
    glPushMatrix();
        glTranslated(-51.0,-2.5,-20.0);
        glScaled(0.2,2.5,3.0);
        drawTexturedCube(10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    // jendela
    glPushMatrix();
        glTranslated(-51.0,27.5,-20.0);
        glScaled(0.05,3.5,3.0);
        jendela();
    glPopMatrix();
}

void dinding(){
    glColor3d(1.0,1.0,1.0);

    glPushMatrix();
        dindingKanan();
    glPopMatrix();

    glPushMatrix();
        dindingBelakang();
    glPopMatrix();

    glPushMatrix();
        glTranslated(-10.0,0.0,0.0);
        dindingKiri();
    glPopMatrix();
}
void kasur() {
    glRotated(270.0, 0.0, 1.0, 0.0);
    
    // Kerangka kasur
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureKayuPutih);
    glColor3d(0.88, 0.72, 0.53);
    glPushMatrix();
        glTranslated(-25.0, -7.5, 0.0);
        glScaled(5.0, 1.0, 4.0);
        drawTexturedCube(10);
    glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	
	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureKayuPutih);
    glPushMatrix();
        glTranslated(-49.0, -4.0, 0.0);
        glScaled(0.1, 2.0, 4.0);
        drawTexturedCube(10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    // Bantal
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureBantal);
    glColor3d(0.53, 0.8, 0.92);
    glPushMatrix();
        glTranslated(-40.0, -2.0, 0.0);
        glScaled(1.0, 0.5, 2.0);
        drawTexturedCube(10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    // Kasur
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureKasur);
    glColor3d(0.95, 0.95, 0.95);
    glPushMatrix();
        glTranslated(-25.0, -2.5, 0.0);
        glScaled(4.6, 0.1, 3.6);
        drawTexturedCube(10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    // Selimut dengan tekstur
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureSelimut);
    glColor3d(1.0, 1.0, 1.0); // Pilih warna putih untuk tekstur
    glPushMatrix();
        glTranslated(-15.0, -2.0, 0.0);
        glScaled(2.5, 0.1, 3.6); // Sesuaikan skala dengan yang ada pada selimut
        drawTexturedCube(10); // Gunakan fungsi drawTexturedCube untuk menggambar dengan tekstur
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}
void meja() {
    // alas atau inti meja
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureKayuPutih);
    glPushMatrix();
        glTranslated(-49.5,0.0,-60.0);
        glScaled(1.8,0.2,1.8);
        drawTexturedCube(10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    // kaki meja
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureKayuCoklat);
    glColor3d(0.88, 0.72, 0.53);
    glPushMatrix();
        glTranslated(-57.5, -7.0, -68.0);
        glScaled(0.2, 1.5, 0.2);
        drawTexturedCube(10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureKayuCoklat);
    glPushMatrix();
        glTranslated(-41.5, -7.0, -52.0);
        glScaled(0.2, 1.5, 0.2);
        drawTexturedCube(10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureKayuCoklat);
    glPushMatrix();
        glTranslated(-57.5, -7.0, -52.0);
        glScaled(0.2, 1.5, 0.2);
        drawTexturedCube(10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureKayuCoklat);;
    glPushMatrix();
        glTranslated(-41.5, -7.0, -68.0);
        glScaled(0.2, 1.5, 0.2);
        drawTexturedCube(10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}
void mejaBelajar(){
    //alas atau inti meja
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureKayuCoklat);
    glColor3d(0.88,0.72,0.53);
    glPushMatrix();
        glTranslated(45.0,7.5,7.0);
        glScaled(2.5,0.2,4.4);
        drawTexturedCube(10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //------------ kerangka ------------------------------------------

    //kaki meja belajar
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureKayuCoklat);
    glPushMatrix();
        glTranslated(56.5,-2.5,-14.0);
        glScaled(0.2,2.0,0.2);
        drawTexturedCube(10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureKayuCoklat);
    glPushMatrix();
        glTranslated(33.5,-2.5,-14.0);
        glScaled(0.2,2.0,0.2);
        drawTexturedCube(10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //inti laci meja belajar
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureKayuPutih);
    glPushMatrix();
        glTranslated(45.0,-2.5,18.0);
        glScaled(2.5,2.0,2.2);
        drawTexturedCube(10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //cover laci meja belajar
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureKayuPutih);
    glColor3d(0.75,0.59,0.4);
    glPushMatrix();
        glTranslated(32.5,-2.5,18.0);
        glScaled(0.05,1.7,1.9);
        drawTexturedCube(10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    //-----------------------------------------------------------------
}

void kursi() {
    // dudukan atau inti kursi
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureKayuPutih);
    glPushMatrix();
        glTranslated(35.0,-6.0,-39.5);
        glScaled(1.4,0.2,1.4);
        drawTexturedCube(10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    
    // Kaki kursi atau kerangka bawah
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureKayuCoklat);
    glPushMatrix();
        glTranslated(29.0,-12.0,-45.5);
        glScaled(0.2,1.3,0.2);
        drawTexturedCube(10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureKayuCoklat);
    glPushMatrix();
        glTranslated(41.0,-12.0,-45.5);
        glScaled(0.2,1.3,0.2);
        drawTexturedCube(10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureKayuCoklat);
    glPushMatrix();
        glTranslated(41.0,-6.0,-33.5);
        glScaled(0.2,2.5,0.2);
        drawTexturedCube(10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureKayuCoklat);
    glPushMatrix();
        glTranslated(29.0,-6.0,-33.5);
        glScaled(0.2,2.5,0.2);
        drawTexturedCube(10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    // Kerangka atas
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureKayuCoklat);
    glPushMatrix();
        glTranslated(35.0, 5.5, -33.5);
        glScaled(1.4, 0.8, 0.2);
        drawTexturedCube(10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    
}
void lemari() {
   // Inisialisasi tekstur kayu
   glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D, textureKayuPutih);
   // Isi atau inti lemari
   glPushMatrix();
       glTranslated(-42.0, 12.0, -48.0);
       glScaled(1.5, 5.5, 4.0);
       drawTexturedCube(10);
   glPopMatrix();
   glDisable(GL_TEXTURE_2D);

 
   // Pintu atau kerangka lemari atas (dengan warna)
   	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureKayuCoklat);
    glPushMatrix();
       glTranslated(-41.0, 26.0, -48.0);
       glScaled(1.5, 2.0, 3.8);
       drawTexturedCube(10);;
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

   // Pintu atau kerangka lemari bawah (dengan warna kayu terang)
   	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureKayuCoklat);
    glPushMatrix();
       glTranslated(-41.0, 5.0, -48.0);
       glScaled(1.5, 2.0, 3.7);
       drawTexturedCube(10);;
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void jam(){
    glColor3d(0.66,0.66,0.66);
    glPushMatrix();
        glTranslated(0.0,45.0,-69.0);
        glScaled(2.0,2.0,0.1);
        glutSolidCube(10);
    glPopMatrix();

    //bingkai jam
    //kanan
    glColor3d(0.44, 0.4, 0.38);
    glPushMatrix();
        glTranslated(9.0,45.0,-68.5);
        glScaled(0.2,2.0,0.15);
        glutSolidCube(10);
    glPopMatrix();
    //kiri
    glPushMatrix();
        glTranslated(-9.0,45.0,-68.5);
        glScaled(0.2,2.0,0.15);
        glutSolidCube(10);
    glPopMatrix();
    //atas
    glPushMatrix();
        glTranslated(0.0,55.0,-68.5);
        glScaled(2.0,0.2,0.15);
        glutSolidCube(10);
    glPopMatrix();
    //bawah
    glPushMatrix();
        glTranslated(0.0,35.0,-68.5);
        glScaled(2.0,0.2,0.15);
        glutSolidCube(10);
    glPopMatrix();

    //arah jarum jam
    glPushMatrix();
        glTranslated(-3.0,45.0,-68.5);
        glScaled(0.5,0.1,0.11);
        glutSolidCube(10);
    glPopMatrix();
    glPushMatrix();
        glTranslated(0.0,48.0,-68.5);
        glScaled(0.1,0.8,0.11);
        glutSolidCube(10);
    glPopMatrix();
}
void buku(){
// =====================================buku 1====================================
    //isi
    glColor3d(0.95,0.95,0.95);
    glPushMatrix();
        glTranslated(35.0,5.0,-64.0);
        glScaled(0.2,0.8,0.8);
        glutSolidCube(10);
    glPopMatrix();

    //cover
    glColor3d(0.3,0.55,0.56);
    glPushMatrix();
        glTranslated(34.0,5.0,-64.0);
        glScaled(0.05,0.9,0.9);
        glutSolidCube(10);
    glPopMatrix();

    glPushMatrix();
        glTranslated(36.0,5.0,-64.0);
        glScaled(0.05,0.9,0.9);
        glutSolidCube(10);
    glPopMatrix();
    // =============================================================================

    // =====================================buku 2====================================
    //isi
    glColor3d(0.95,0.95,0.95);
    glPushMatrix();
        glTranslated(37.5,5.0,-64.0);
        glScaled(0.2,0.8,0.8);
        glutSolidCube(10);
    glPopMatrix();

    //cover
    glColor3d(0.55,0.02,0.0);
    glPushMatrix();
        glTranslated(36.5,5.0,-64.0);
        glScaled(0.05,0.9,0.9);
        glutSolidCube(10);
    glPopMatrix();

    glPushMatrix();
        glTranslated(38.5,5.0,-64.0);
        glScaled(0.05,0.9,0.9);
        glutSolidCube(10);
    glPopMatrix();
    // =============================================================================

    // =====================================buku 3====================================
    //isi
    glColor3d(0.95,0.95,0.95);
    glPushMatrix();
        glTranslated(40.0,5.0,-64.0);
        glScaled(0.2,0.8,0.8);
        glutSolidCube(10);
    glPopMatrix();

    //cover
    glColor3d(0.18,0.31,0.31);
    glPushMatrix();
        glTranslated(39.0,5.0,-64.0);
        glScaled(0.05,0.9,0.9);
        glutSolidCube(10);
    glPopMatrix();

    glPushMatrix();
        glTranslated(41.0,5.0,-64.0);
        glScaled(0.05,0.9,0.9);
        glutSolidCube(10);
    glPopMatrix();
    // =============================================================================
}

void karpet(){
    //dasar
    glColor3d(0.3, 0.23, 0.23);
    glPushMatrix();
        glTranslatef(-24.0,-12.75,5.5);
        glScalef(7.0, 0.05, 4.7);
        glutSolidCube(10);
    glPopMatrix();
    //motif karpet

    //warna merah kotak 1 dan 4
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureKarpetMerah);
    glPushMatrix();
        glColor3d(0.5, 0.4, 0.4);
        glTranslatef(-24.0,-12.75,5.5);
        glScalef(6.5, 0.06, 4.4);
        drawTexturedCube(10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //warna coklat muda kotak 2 dan 3
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureKarpetPutih);
    glPushMatrix();
        glTranslatef(-7.5,-12.75,-5.5);
        glScalef(3.25, 0.065, 2.2);
        drawTexturedCube(10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureKarpetPutih);
    glPushMatrix();
        glTranslatef(-40.5,-12.75,16.5);
        glScalef(3.25, 0.065, 2.2);
        drawTexturedCube(10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}
void laptop(){
    //keyboard
    glPushMatrix();
        glColor3d(-5.4, 0.4, 0.4);
        glTranslatef(45.0,9.0,-2.5);
        glScalef(1.5, 0.1, 1.8);
        glutSolidCube(10);
    glPopMatrix();

    glPushMatrix();
        glColor3d(0.2, 0.2, 0.2);
        glTranslatef(46.0,9.05,-2.5);
        glScalef(0.8, 0.11, 1.5);
        glutSolidCube(10);
    glPopMatrix();

    //monitor / layar
    glColor3d(0.4, 0.4, 0.4);
    glPushMatrix();
        glRotated(-120.0,0.0,0.0,1.0);
        glTranslatef(-40.0,41.0,-2.5);
        glScalef(1.5, 0.1, 1.8);
        glutSolidCube(10);
    glPopMatrix();

    glColor3d(0.85, 0.85, 0.85);
    glPushMatrix();
        glRotated(-120.0,0.0,0.0,1.0);
        glTranslatef(-40.0,41.0,-2.5);
        glScalef(1.3, 0.11, 1.6);
        glutSolidCube(10);
    glPopMatrix();
}
void lampuMeja(){
    // alas
    glColor3d(0.44, 0.4, 0.38);
    glPushMatrix();
        glTranslated(-49.5,3.0,-60.0);
        glScaled(0.8,0.2,0.8);
        glutSolidCube(10);
    glPopMatrix();
    //tiang
    glPushMatrix();
        glTranslated(-49.5,12.0,-60.0);
        glScaled(0.1,1.8,0.1);
        glutSolidCube(10);
    glPopMatrix();
    //lampu
    glPushMatrix();
        glTranslated(-49.5,21.0,-60.0);
        glScaled(1.2,0.08,1.2);
        glutSolidCube(10);
    glPopMatrix();
    glPushMatrix();
        glTranslated(-49.5,17.25,-54.25);
        glScaled(1.2,0.8,0.08);
        glutSolidCube(10);
    glPopMatrix();
    glPushMatrix();
        glTranslated(-49.5,17.25,-65.75);
        glScaled(1.2,0.8,0.08);
        glutSolidCube(10);
    glPopMatrix();
    glPushMatrix();
        glTranslated(-55.25,17.25,-60.0);
        glScaled(0.08,0.8,1.2);
        glutSolidCube(10);
    glPopMatrix();
    glPushMatrix();
        glTranslated(-43.75,17.25,-60.0);
        glScaled(0.08,0.8,1.2);
        glutSolidCube(10);
    glPopMatrix();
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLfloat lightPos[] = { -16.0f, 10.0f, 15.0f, 1.0f }; // Posisi cahaya sesuai koordinat yang diberikan
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

    glPushMatrix();
    glTranslatef(-16.0f, 10.0f, 15.0f); // Posisikan bola di tempat yang sama dengan sumber cahaya
    glColor3f(1.0f, 1.0f, 0.0f); // Warna bola kuning
    glutSolidSphere(0.5, 20, 20); // Gambar bola yang lebih besar
    glPopMatrix();
    glRotatef(angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(angleY, 0.0f, 1.0f, 0.0f);

    //============================ Ruangan ======================
    glPushMatrix();
        ubin();
    glPopMatrix();

    glPushMatrix();
        dinding();
    glPopMatrix();
    //======================================================================

    //============================= kasur ==================================
    glPushMatrix();
        glTranslated(-18.0,0.0,-19.0);
        kasur();
    glPopMatrix();
    //=====================================================================

    //============================= MEJA BELAJAR ==============================
    glPushMatrix();
        mejaBelajar();
    glPopMatrix();
    //=====================================================================

    //============================= meja ==================================
    glPushMatrix();
        glRotated(0.0,0.0,1.0,0.0);
        glTranslated(0.0,1.5,0.0);
        meja();
    glPopMatrix();
    //=====================================================================

    //============================= kursi ==================================
    glPushMatrix();
        glRotated(-90.0,0.0,1.0,0.0);
        glTranslated(-38.0,5.0,10.0);
        kursi();
    glPopMatrix();
    //=====================================================================

    //============================Lemari==================================
    glPushMatrix();
        glRotated(-90.0,0.0,1.0,0.0);
        glTranslated(-19.0,1.0,5.0);
        glScaled(1.0,1.0,0.8);
        lemari();
    glPopMatrix();
    //=====================================================================

    //================================= JAM ====================================
    glPushMatrix();
        jam();
    glPopMatrix();
    //=====================================================================
    //============================= KARPET ==================================
    glPushMatrix();
        karpet();
    glPopMatrix();
    //=====================================================================
    // =============================== BUKU ================================
    glPushMatrix();
        glRotated(-90.0,0.0,1.0,0.0);
        glTranslated(-14.0,8.0,12.0);
        buku();
    glPopMatrix();
    // =============================================================================
    //============================= LAPTOP ==================================
    glPushMatrix();
        laptop();
    glPopMatrix();
    //=====================================================================
    //============================= LAMPU MEJA ==================================
    glPushMatrix();
        lampuMeja();
    glPopMatrix();
    //=====================================================================


    glFlush();
    glutSwapBuffers();
}
//****************************************************************************************************************************
//****************************************** fungsi init **********************************************************************
void init() {
   glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1); // Mengaktifkan sumber cahaya tambahan untuk lampu meja
    glEnable(GL_COLOR_MATERIAL); // Mengaktifkan pelacakan warna material

    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE); // Mengatur properti material untuk mengikuti nilai glColor

    glClearColor(0.0, 0.0, 0.0, 1.0);

    // Inisialisasi cahaya ambient yang lebih rendah
    GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);

    // Inisialisasi sumber cahaya difus yang lebih terang
    GLfloat diffuseLight0[] = { 0.8f, 0.8f, 0.7f, 1.0f }; 
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight0);

    // Inisialisasi cahaya spekular untuk highlight
    GLfloat specularLight0[] = { 0.5f, 0.5f, 0.5f, 1.0f };
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight0);

    // Mengatur posisi sumber cahaya utama
    GLfloat lightPosition0[] = { -49.5f, 25.0f, -60.0f, 1.0f }; 
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition0);

    // Mengatur atenuasi cahaya untuk efek natural
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.5f);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.1f);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.01f);

    // Inisialisasi sumber cahaya tambahan untuk lampu meja
    GLfloat diffuseLight1[] = { 1.0f, 1.0f, 0.8f, 1.0f };
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseLight1);

    GLfloat specularLight1[] = { 1.0f, 1.0f, 0.8f, 1.0f };
    glLightfv(GL_LIGHT1, GL_SPECULAR, specularLight1);

    GLfloat lightPosition1[] = { -49.5f, 21.0f, -60.0f, 1.0f };
    glLightfv(GL_LIGHT1, GL_POSITION, lightPosition1);

    glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 0.5f);
    glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.1f);
    glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.01f);
    
    textureKayuCoklat = loadTexture("kayu-coklat.jpeg");
    if (textureKayuCoklat == 0) {
        std::cerr << "Error: Unable to load texture kayu-coklat.jpeg" << std::endl;
        exit(EXIT_FAILURE);
    }
    textureKayuPutih = loadTexture("kayu-putih.jpg");
    if (textureKayuPutih == 0) {
        std::cerr << "Error: Unable to load texture kayu-putih.jpg" << std::endl;
        exit(EXIT_FAILURE);
    }
    textureSelimut = loadTexture("selimut-abu.png");
    if (textureSelimut == 0) {
        std::cerr << "Error: Unable to load texture selimut.png" << std::endl;
        exit(EXIT_FAILURE);
    }
    textureKasur = loadTexture("kasur.jpg");
    if (textureKasur == 0) {
        std::cerr << "Error: Unable to load texture kasur.jpg" << std::endl;
        exit(EXIT_FAILURE);
    }
    textureBantal = loadTexture("bantal.jpg");
    if (textureBantal == 0) {
        std::cerr << "Error: Unable to load texture bantal.jpg" << std::endl;
        exit(EXIT_FAILURE);
    }
    textureKeramik = loadTexture("keramik.png");
    if (textureKeramik == 0) {
        std::cerr << "Error: Unable to load texture keramik.png" << std::endl;
        exit(EXIT_FAILURE);
    }
    textureKarpetMerah = loadTexture("karpet-merah.jpg");
    if (textureKarpetMerah == 0) {
        std::cerr << "Error: Unable to load texture karpet-merah.jpg" << std::endl;
        exit(EXIT_FAILURE);
    }
    textureKarpetPutih = loadTexture("karpet-putih.jpg");
    if (textureKarpetPutih == 0) {
        std::cerr << "Error: Unable to load texture karpet-putih.jpg" << std::endl;
        exit(EXIT_FAILURE);
    }
    textureTembok = loadTexture("tembok.jpeg");
    if (textureTembok == 0) {
        std::cerr << "Error: Unable to load texture tembok.jpeg" << std::endl;
        exit(EXIT_FAILURE);
    }
}

//****************************************************************************************************************************
//********************************************** fungsi reshape **************************************************************
void reshape(int w, int h){
    glViewport(0,0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 400.0);
    glTranslated(0.0, -45.0, -100.0);
    gluLookAt(0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glMatrixMode(GL_MODELVIEW);
}
//****************************************************************************************************************************
//********************************************** fungsi keyboard *************************************************************
void keyboard(unsigned char key, int x, int y)
{

switch (key)
{
case 'a':
 case 'A':
 glTranslated(1.0, 0.0, 0.0);//geser kiri
 break;
 case 'd':
 case 'D':
 glTranslated(-1.0, 0.0, 0.0);//geser kanan
 break;
 case 's':
 case 'S':
 glTranslated(0.0, 0.0, -1.0);//dalam objek
 break;
 case 'w':
 case 'W':
 glTranslated(0.0, 0.0, 1.0);//keluar objek
 break;
     case 27: // kode ASCII untuk tombol Esc
        exit(0); // keluar aplikasi
        break;
                case '1': // Menyalakan cahaya
            glEnable(GL_LIGHT0);
            lightOn = true;
            break;
        case '2': // Mematikan cahaya
            glDisable(GL_LIGHT0);
            lightOn = false;
            break;

}

    glutPostRedisplay();
}
//*****************************************************************************************************************************************
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ad
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ PROGRAM UTAMA ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main (int argc, char** argv){
    glutInit(&argc, argv);
    glutInitWindowSize(1152, 680);
    glutInitWindowPosition(20, 10);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Project GLUT 3D");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutKeyboardFunc(keyboard); // +3 memanggil fungsi keyboard
    glutMotionFunc(mouseMotion);
    glutPassiveMotionFunc(mouseMotion);
    glutWarpPointer(windowWidth / 2, windowHeight / 2);
    init();
    glutMainLoop();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

