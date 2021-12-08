#include "TextureBuilder.h"
#include <math.h>
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <iostream>
#include <MMSystem.h>
using namespace std;
#include <glut.h>
//curve 1
int p0[2];
int p1[2];
int p2[2];
int p3[2];
//curve 2
int p4[2];
int p5[2];
int p6[2];
int p7[2];
//curve 3
int p8[2];
int p9[2];
int p10[2];
int p11[2];
//curve 4
int p12[2];
int p13[2];
int p14[2];
int p15[2];
//Global Variables
int healthbarx1 = 930;
int healthbarx2 = 400;
int x;
int y;
int r;
int q;
int s1;
int s2;
float powerlevel = 0;
float step = 0;
float wing = 0;
float c = 20;
float d = 20;
float t = 0;
float mousepx;
float mousepy;
bool flag = true;
bool turnc = true;
bool turnd = true;
bool leftmouse;
bool flagm;
bool start = false;
char* applecondition = " ";
char* carrotmsg = " ";
char* seed = " ";
char* leaf = " ";
int* bezier(float t, int* p0, int* p1, int* p2, int* p3)
{
	int res[2];
	res[0] = pow((1 - t), 3) * p0[0] + 3 * t * pow((1 - t), 2) * p1[0] + 3 * pow(t, 2) * (1 - t) * p2[0] + pow(t, 3) * p3[0];
	res[1] = pow((1 - t), 3) * p0[1] + 3 * t * pow((1 - t), 2) * p1[1] + 3 * pow(t, 2) * (1 - t) * p2[1] + pow(t, 3) * p3[1];
	return res;
}
void print(int x, int y, char* string)
{
	int len, i;
	glRasterPos2f(x, y);
	len = (int)strlen(string);
	for (i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
	}
}
void mouse1(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) {
		leftmouse = (state == GLUT_DOWN);
		flagm = !leftmouse;
	}
	mousepx = x;
	mousepy = y;
	s1 = x;
	s2 = 620 - y;
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && s1 > 450 && s1 < 550 && s2>100 && s2 < 140) {
		start = false;
	}
	else (button == GLUT_LEFT_BUTTON && state == GLUT_UP && s1 > 450 && s1 < 550 && s2>100 && s2 < 140); {
		start = true;
		cout << "dakhalll";

	}
	glutPostRedisplay();
}
void mouse2() {
	if (leftmouse == true) {
		if (mousepx > 150 && mousepx < 250) {
			if (c < 180 && healthbarx1 > 630 && healthbarx2 > 100) {
				c = c + 0.05;
				d = 20;
			}
		}
		if (mousepx > 750 && mousepx < 850) {
			if (d < 180 && healthbarx1 > 630 && healthbarx2 > 100) {
				d = d + 0.05;
				c = 20;
			}
		}
	}
	if (flagm == true && healthbarx1 > 630 && healthbarx2 > 100) {
		if (t >= 1) {
			turnc = true;
			turnd = true;
			t = 0;
			applecondition = "...... ";
			carrotmsg = " ......";
		}
		if (t < 1) {
			if (c > 20 && c < 60 && turnc == true) {
				int* p = bezier(t, p0, p1, p2, p3);
				x = p[0];
				y = p[1];
				if (p0[0] == x && p0[1] == y) {
					turnc = !turnc;
				}
			}
			if (c > 60 && c < 100 && turnc == true) {
				int* p = bezier(t, p4, p5, p6, p7);
				x = p[0];
				y = p[1];
				if (p4[0] == x && p4[1] == y) {
					turnc = !turnc;
				}
			}
			if (c > 100 && c < 140 && turnc == true) {
				int* p = bezier(t, p8, p9, p10, p11);
				x = p[0];
				y = p[1];
				if (p8[0] == x && p8[1] == y) {
					turnc = !turnc;
				}
			}
			if (c > 140 && c < 180 && turnc == true) {
				int* p = bezier(t, p12, p13, p14, p15);
				x = p[0];
				y = p[1];
				if (p12[0] == x && p12[1] == y) {
					turnc = !turnc;
					c = 20;
					carrotmsg = "DAMN IT!";
					applecondition = "SURPRISE MODAFUCKA!";
					if (healthbarx1 > 630) {
						healthbarx1 = healthbarx1 - 100;
					}
				}
			}
			if (d > 20 && d < 60 && turnd == true) {

				int* p = bezier(t, p0, p1, p2, p3);
				r = p[0];
				q = p[1];
				if (p0[0] == r && p0[1] == q) {
					turnd = !turnd;
				}
			}
			if (d >= 60 && d <= 100 && turnd == true) {
				int* p = bezier(t, p4, p5, p6, p7);
				r = p[0];
				q = p[1];
				if (p4[0] == r && p4[1] == q) {
					turnd = !turnd;
				}
			}
			if (d >= 100 && d <= 140 && turnd == true) {
				int* p = bezier(t, p8, p9, p10, p11);
				r = p[0];
				q = p[1];
				if (p8[0] == r && p8[1] == q) {
					turnd = !turnd;
				}
			}
			if (d >= 140 && d <= 180 && turnd == true) {
				int* p = bezier(t, p12, p13, p14, p15);
				r = p[0];
				q = p[1];
				if (p12[0] == r && p12[1] == q) {
					turnd = !turnd;
					applecondition = "DAMN IT!";
					carrotmsg = "SURPRISE MODAFUCKA!";
					if (healthbarx2 > 100) {
						healthbarx2 = healthbarx2 - 100;

					}
				}
			}
			t += 0.0002;
		}
	}
}
void Display() {
	glClear(GL_COLOR_BUFFER_BIT);
	if (start == false) {
		if (healthbarx1 > 630 && healthbarx2 > 100) {
			glBegin(GL_POLYGON);
			glColor3f(0.9, 1, 0.3);
			glVertex3f(0, 0, 0);
			glVertex3f(0, 620, 0);
			glColor3f(1, 0.2, 0.3);
			glVertex3f(1000, 620, 0);
			glVertex3f(1000, 0, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glColor3f(1, 0, 0);
			glVertex3f(450, 100, 0);
			glVertex3f(450, 140, 0);
			glVertex3f(550, 140, 0);
			glVertex3f(550, 100, 0);
			glEnd();
			glBegin(GL_LINE_LOOP);
			glColor3f(0, 0, 0);
			glVertex3f(450, 100, 0);
			glVertex3f(450, 140, 0);
			glVertex3f(550, 140, 0);
			glVertex3f(550, 100, 0);
			glEnd();
			print(400, 550, "Welcome To My First Ever Game");
			print(440, 520, "Fruits Vs Vegetables");
			print(400, 370, "Instructions:");
			print(400, 340, "1.Put The Mouse on The Character");
			print(400, 310, "2.Press And Hold The Left Click Mouse");
			print(400, 280, "3.Release The Mouse To Shoot");
			print(480, 115, "Start");
			print(850, 20, "Created By ARK");
			
		}
	}
	else {
		if (healthbarx1 > 630 && healthbarx2 > 100) {
			glBegin(GL_POLYGON);
			glColor3f(1, 0, 0.3);
			glVertex3f(0, 620, 0);
			glVertex3f(0, 200, 0);
			glColor3f(0.1, 0.1, 0.3);
			glVertex3f(1000, 200, 0);
			glVertex3f(1000, 620, 0);
			glEnd();
			glPushMatrix();
			glTranslated(-25, 0, 0);
			glBegin(GL_POLYGON);                                             //shaffatt
			glColor3f(0.5, 0.1, 1);
			glVertex3f(450, 570, 0);
			glVertex3f(450, 430, 0);
			glVertex3f(640, 430, 0);
			glVertex3f(640, 570, 0);
			glEnd();
			glBegin(GL_LINE_LOOP);                                           // shaffatt
			glColor3f(0, 0, 0);
			glVertex3f(450, 570, 0);
			glVertex3f(450, 430, 0);
			glVertex3f(640, 430, 0);
			glVertex3f(640, 570, 0);
			glEnd();
			glBegin(GL_POLYGON);                                             //shaffatt
			glColor3f(0.5, 1, 0.6);
			glVertex3f(470, 550, 0);
			glVertex3f(470, 450, 0);
			glVertex3f(620, 450, 0);
			glVertex3f(620, 550, 0);
			glEnd();
			glBegin(GL_LINE_LOOP);                                           //shaffatt
			glColor3f(0, 0, 0);
			glVertex3f(470, 550, 0);
			glVertex3f(470, 450, 0);
			glVertex3f(620, 450, 0);
			glVertex3f(620, 550, 0);
			glEnd();
			glPushMatrix();
			glTranslated(539, 507, 0);
			glRotated(wing, 0, 0, 1);
			glTranslated(-539, -507, 0);
			glBegin(GL_POLYGON);
			glColor3f(0.8, 0.4, 0.9);
			glVertex3f(530, 515, 0);
			glVertex3f(530, 530, 0);
			glVertex3f(550, 545, 0);
			glVertex3f(570, 545, 0);
			glVertex3f(550, 530, 0);
			glVertex3f(550, 515, 0);
			glEnd();
			glBegin(GL_LINE_LOOP);
			glColor3f(0, 0, 0);
			glVertex3f(530, 515, 0);
			glVertex3f(530, 530, 0);
			glVertex3f(550, 545, 0);
			glVertex3f(570, 545, 0);
			glVertex3f(550, 530, 0);
			glVertex3f(550, 515, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glColor3f(0.8, 0.4, 0.9);
			glVertex3f(550, 515, 0);
			glVertex3f(565, 515, 0);
			glVertex3f(585, 495, 0);
			glVertex3f(585, 475, 0);
			glVertex3f(565, 495, 0);
			glVertex3f(550, 495, 0);
			glEnd();
			glBegin(GL_LINE_LOOP);
			glColor3f(0, 0, 0);
			glVertex3f(550, 515, 0);
			glVertex3f(565, 515, 0);
			glVertex3f(585, 495, 0);
			glVertex3f(585, 475, 0);
			glVertex3f(565, 495, 0);
			glVertex3f(550, 495, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glColor3f(0.8, 0.4, 0.9);
			glVertex3f(530, 495, 0);
			glVertex3f(515, 495, 0);
			glVertex3f(495, 505, 0);
			glVertex3f(495, 525, 0);
			glVertex3f(515, 515, 0);
			glVertex3f(530, 515, 0);
			glEnd();
			glBegin(GL_LINE_LOOP);
			glColor3f(0, 0, 0);
			glVertex3f(530, 495, 0);
			glVertex3f(515, 495, 0);
			glVertex3f(495, 505, 0);
			glVertex3f(495, 525, 0);
			glVertex3f(515, 515, 0);
			glVertex3f(530, 515, 0);
			glEnd();
			glPopMatrix();
			glPushMatrix();
			glColor3f(0, 0, 0);
			glTranslated(539, 507, 0);
			GLUquadric* f = gluNewQuadric();
			gluDisk(f, 0, 13, 50, 50);
			glPopMatrix();
			glPopMatrix();
			glBegin(GL_POLYGON);                                          //floor
			glColor3f(0.2, 0.7, 1);
			glVertex3f(0, 200, 0);
			glColor3f(1, 0.4, 0.7);
			glVertex3f(0, 0, 0);
			glColor3f(0.8, 0.4, 1);
			glVertex3f(1000, 0, 0);
			glColor3f(0.1, 1, 0.8);
			glVertex3f(1000, 200, 0);
			glEnd();
			glBegin(GL_LINE_LOOP);                                       //floor 
			glColor3f(0, 0, 0);
			glVertex3f(0, 200, 0);
			glVertex3f(0, 0, 0);
			glVertex3f(1000, 0, 0);
			glVertex3f(1000, 200, 0);
			glEnd();
			glBegin(GL_POLYGON);                                             //fridge
			glColor3f(1, 1, 1);
			glVertex3f(400, 350, 0);
			glVertex3f(400, 0, 0);
			glVertex3f(600, 0, 0);
			glVertex3f(600, 350, 0);
			glEnd();
			glBegin(GL_LINE_LOOP);                                           //fridge
			glColor3f(0, 0, 0);
			glVertex3f(400, 350, 0);
			glVertex3f(400, 0, 0);
			glVertex3f(600, 0, 0);
			glVertex3f(600, 350, 0);
			glEnd();
			glBegin(GL_QUADS);
			glColor3f(1, 0.5, 0.5);
			glVertex3f(400, 350, 0);
			glVertex3f(430, 360, 0);
			glVertex3f(630, 360, 0);
			glVertex3f(600, 350, 0);
			glEnd();
			glBegin(GL_QUADS);
			glColor3f(1, 0.5, 0.5);
			glVertex3f(600, 350, 0);
			glVertex3f(600, 0, 0);
			glVertex3f(630, 10, 0);
			glVertex3f(630, 360, 0);
			glEnd();
			glBegin(GL_LINES);
			glColor3f(0, 0, 0);
			glVertex3f(400, 350, 0);
			glVertex3f(430, 360, 0);
			glVertex3f(600, 350, 0);
			glVertex3f(630, 360, 0);
			glVertex3f(430, 360, 0);
			glVertex3f(630, 360, 0);
			glVertex3f(630, 360, 0);
			glVertex3f(630, 10, 0);
			glVertex3f(400, 350, 0);
			glVertex3f(600, 350, 0);
			glVertex3f(600, 0, 0);
			glVertex3f(630, 10, 0);
			glEnd();
			glLineWidth(10.0);
			glBegin(GL_LINE_STRIP);
			glColor3f(1, 0, 0);
			glVertex3f(540, 300, 0);
			glVertex3f(460, 300, 0);
			glVertex3f(460, 200, 0);
			glVertex3f(540, 200, 0);
			glVertex3f(540, 240, 0);
			glVertex3f(495, 240, 0);
			glEnd();
			glBegin(GL_LINE_STRIP);
			glColor3f(1, 0, 0);
			glVertex3f(410, 80, 0);
			glVertex3f(410, 10, 0);
			glVertex3f(490, 10, 0);
			glVertex3f(490, 80, 0);
			glEnd();
			glBegin(GL_LINE_STRIP);
			glColor3f(1, 0, 0);
			glVertex3f(580, 80, 0);
			glVertex3f(520, 80, 0);
			glVertex3f(520, 10, 0);
			glVertex3f(580, 10, 0);
			glEnd();
			glLineWidth(4.0);
			glBegin(GL_POLYGON);                                            // el center
			glColor3f(0, 0, 0);
			glVertex3f(400, 185, 0);
			glVertex3f(400, 165, 0);
			glVertex3f(600, 165, 0);
			glVertex3f(600, 185, 0);
			glEnd();
			glBegin(GL_LINE_LOOP);
			glColor3f(0, 0, 0);
			glVertex3f(400, 185, 0);
			glVertex3f(400, 165, 0);
			glVertex3f(600, 165, 0);
			glVertex3f(600, 185, 0);
			glEnd();
			glBegin(GL_POLYGON);                                             //el 2oqar
			glColor3f(0.5, 0.5, 0.5);
			glVertex3f(420, 260, 0);
			glVertex3f(420, 230, 0);
			glVertex3f(440, 230, 0);
			glVertex3f(440, 260, 0);
			glEnd();
			glBegin(GL_LINE_LOOP);                                           //el 2oqar
			glColor3f(0, 0, 0);
			glVertex3f(420, 260, 0);
			glVertex3f(420, 230, 0);
			glVertex3f(440, 230, 0);
			glVertex3f(440, 260, 0);
			glEnd();
			glBegin(GL_POLYGON);                                             //el 2oqra 2
			glColor3f(0.5, 0.5, 0.5);
			glVertex3f(420, 140, 0);
			glVertex3f(420, 110, 0);
			glVertex3f(440, 110, 0);
			glVertex3f(440, 140, 0);
			glEnd();
			glBegin(GL_LINE_LOOP);                                           //el 2oqra 2
			glColor3f(0, 0, 0);
			glVertex3f(420, 140, 0);
			glVertex3f(420, 110, 0);
			glVertex3f(440, 110, 0);
			glVertex3f(440, 140, 0);
			glEnd();
			glBegin(GL_POLYGON);                                             //el dalfa elly taht
			glColor3f(1, 0.5, 1);
			glVertex3f(50, 350, 0);
			glVertex3f(50, 200, 0);
			glVertex3f(350, 200, 0);
			glVertex3f(350, 350, 0);
			glEnd();
			glBegin(GL_LINE_LOOP);                                           //el dalfa elly taht
			glColor3f(0, 0, 0);
			glVertex3f(50, 350, 0);
			glVertex3f(50, 200, 0);
			glVertex3f(350, 200, 0);
			glVertex3f(350, 350, 0);
			glEnd();
			glBegin(GL_LINES);
			glColor3f(0, 0, 0);
			glVertex3f(260, 200, 0);
			glVertex3f(260, 350, 0);
			glVertex3f(170, 200, 0);
			glVertex3f(170, 350, 0);
			glVertex3f(110, 200, 0);
			glVertex3f(110, 350, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glColor3f(0, 0.04, 0.7);
			glVertex3f(80, 360, 0);
			glVertex3f(50, 350, 0);
			glVertex3f(350, 350, 0);
			glVertex3f(380, 360, 0);
			glEnd();
			glBegin(GL_LINES);
			glColor3f(0, 0, 0);
			glVertex3f(80, 360, 0);
			glVertex3f(50, 350, 0);
			glVertex3f(350, 350, 0);
			glVertex3f(380, 360, 0);
			glVertex3f(80, 360, 0);
			glVertex3f(380, 360, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glColor3f(0, 0.04, 0.7);
			glVertex3f(350, 350, 0);
			glVertex3f(350, 200, 0);
			glVertex3f(380, 210, 0);
			glVertex3f(380, 360, 0);
			glEnd();
			glBegin(GL_POLYGON);                                             //el 2oqar 3 
			glColor3f(0.5, 0.5, 0.5);
			glVertex3f(80, 305, 0);
			glVertex3f(80, 275, 0);
			glVertex3f(100, 275, 0);
			glVertex3f(100, 305, 0);
			glEnd();
			glBegin(GL_LINE_LOOP);                                           //el 2oqar 3
			glColor3f(0, 0, 0);
			glVertex3f(80, 305, 0);
			glVertex3f(80, 275, 0);
			glVertex3f(100, 275, 0);
			glVertex3f(100, 305, 0);
			glEnd();
			glBegin(GL_POLYGON);                                             //el 2oqar 4
			glColor3f(0.5, 0.5, 0.5);
			glVertex3f(120, 305, 0);
			glVertex3f(120, 275, 0);
			glVertex3f(140, 275, 0);
			glVertex3f(140, 305, 0);
			glEnd();
			glBegin(GL_LINE_LOOP);                                           //el 2oqar 4
			glColor3f(0, 0, 0);
			glVertex3f(120, 305, 0);
			glVertex3f(120, 275, 0);
			glVertex3f(140, 275, 0);
			glVertex3f(140, 305, 0);
			glEnd();
			glBegin(GL_POLYGON);                                             //el 2oqar 5
			glColor3f(0.5, 0.5, 0.5);
			glVertex3f(230, 305, 0);
			glVertex3f(230, 275, 0);
			glVertex3f(250, 275, 0);
			glVertex3f(250, 305, 0);
			glEnd();
			glBegin(GL_LINE_LOOP);                                           //el 2oqar 5
			glColor3f(0, 0, 0);
			glVertex3f(230, 305, 0);
			glVertex3f(230, 275, 0);
			glVertex3f(250, 275, 0);
			glVertex3f(250, 305, 0);
			glEnd();
			glBegin(GL_POLYGON);                                             //el 2oqar 6
			glColor3f(0.5, 0.5, 0.5);
			glVertex3f(270, 305, 0);
			glVertex3f(270, 275, 0);
			glVertex3f(290, 275, 0);
			glVertex3f(290, 305, 0);
			glEnd();
			glBegin(GL_LINE_LOOP);                                           //el 2oqar 6
			glColor3f(0, 0, 0);
			glVertex3f(270, 305, 0);
			glVertex3f(270, 275, 0);
			glVertex3f(290, 275, 0);
			glVertex3f(290, 305, 0);
			glEnd();
			glBegin(GL_POLYGON);                                             //el dalfa elly taht 2
			glColor3f(0.60, 0.40, 0.70);
			glVertex3f(650, 350, 0);
			glVertex3f(650, 200, 0);
			glVertex3f(900, 200, 0);
			glVertex3f(900, 350, 0);
			glEnd();
			glBegin(GL_LINE_LOOP);                                           //el dalfa elly taht 2
			glColor3f(0, 0, 0);
			glVertex3f(650, 350, 0);
			glVertex3f(650, 200, 0);
			glVertex3f(900, 200, 0);
			glVertex3f(900, 350, 0);
			glEnd();
			glBegin(GL_LINES);
			glColor3f(0, 0, 0);
			glVertex3f(850, 200, 0);
			glVertex3f(850, 350, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glColor3f(1, 1, 0);
			glVertex3f(650, 350, 0);
			glVertex3f(680, 360, 0);
			glVertex3f(930, 360, 0);
			glVertex3f(900, 350, 0);
			glEnd();
			glBegin(GL_LINES);
			glColor3f(0, 0, 0);
			glVertex3f(650, 350, 0);
			glVertex3f(680, 360, 0);
			glVertex3f(680, 360, 0);
			glVertex3f(930, 360, 0);
			glVertex3f(930, 360, 0);
			glVertex3f(900, 350, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glColor3f(1, 1, 0);
			glVertex3f(930, 360, 0);
			glVertex3f(900, 350, 0);
			glVertex3f(900, 200, 0);
			glVertex3f(930, 210, 0);
			glEnd();
			glBegin(GL_LINES);
			glColor3f(0, 0, 0);
			glVertex3f(900, 350, 0);
			glVertex3f(930, 360, 0);
			glVertex3f(930, 360, 0);
			glVertex3f(930, 210, 0);
			glVertex3f(930, 210, 0);
			glVertex3f(900, 200, 0);
			glVertex3f(650, 350, 0);
			glVertex3f(900, 350, 0);
			glEnd();
			glBegin(GL_POLYGON);                                             //el 2oqar 7
			glColor3f(0.5, 0.5, 0.5);
			glVertex3f(860, 305, 0);
			glVertex3f(860, 275, 0);
			glVertex3f(880, 275, 0);
			glVertex3f(880, 305, 0);
			glEnd();
			glBegin(GL_LINE_LOOP);                                           //el 2oqar 7
			glColor3f(0, 0, 0);
			glVertex3f(860, 305, 0);
			glVertex3f(860, 275, 0);
			glVertex3f(880, 275, 0);
			glVertex3f(880, 305, 0);
			glEnd();
			glBegin(GL_POLYGON);                                             //el 2oqar 8
			glColor3f(0.5, 0.5, 0.5);
			glVertex3f(820, 305, 0);
			glVertex3f(820, 275, 0);
			glVertex3f(840, 275, 0);
			glVertex3f(840, 305, 0);
			glEnd();
			glBegin(GL_LINE_LOOP);                                           //el 2oqar 8
			glColor3f(0, 0, 0);
			glVertex3f(820, 305, 0);
			glVertex3f(820, 275, 0);
			glVertex3f(840, 275, 0);
			glVertex3f(840, 305, 0);
			glEnd();
			glBegin(GL_POLYGON);                                             //el dalfa elly fo2
			glColor3f(1, 0.24, 0.52);
			glVertex3f(750, 550, 0);
			glVertex3f(750, 450, 0);
			glVertex3f(900, 450, 0);
			glVertex3f(900, 550, 0);
			glEnd();
			glBegin(GL_LINE_LOOP);                                           //el dalfa elly fo2 
			glColor3f(0, 0, 0);
			glVertex3f(750, 550, 0);
			glVertex3f(750, 450, 0);
			glVertex3f(900, 450, 0);
			glVertex3f(900, 550, 0);
			glEnd();
			glBegin(GL_LINES);
			glColor3f(0, 0, 0);
			glVertex3f(825, 450, 0);
			glVertex3f(825, 550, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glColor3f(0.6, 0, 1);
			glVertex3f(750, 550, 0);
			glVertex3f(780, 560, 0);
			glVertex3f(930, 560, 0);
			glVertex3f(900, 550, 0);
			glEnd();
			glBegin(GL_LINES);
			glColor3f(0, 0, 0);
			glVertex3f(750, 550, 0);
			glVertex3f(780, 560, 0);
			glVertex3f(780, 560, 0);
			glVertex3f(930, 560, 0);
			glVertex3f(930, 560, 0);
			glVertex3f(900, 550, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glColor3f(0.6, 0, 1);
			glVertex3f(930, 560, 0);
			glVertex3f(900, 550, 0);
			glVertex3f(900, 450, 0);
			glVertex3f(930, 460, 0);
			glEnd();
			glBegin(GL_LINES);
			glColor3f(0, 0, 0);
			glVertex3f(900, 550, 0);
			glVertex3f(930, 560, 0);
			glVertex3f(930, 560, 0);
			glVertex3f(930, 460, 0);
			glVertex3f(930, 460, 0);
			glVertex3f(900, 450, 0);
			glVertex3f(900, 450, 0);
			glVertex3f(900, 550, 0);
			glVertex3f(750, 550, 0);
			glVertex3f(900, 550, 0);
			glEnd();
			glBegin(GL_POLYGON);                                             //el 2oqar 9
			glColor3f(0.5, 0.5, 0.5);
			glVertex3f(795, 515, 0);
			glVertex3f(795, 485, 0);
			glVertex3f(815, 485, 0);
			glVertex3f(815, 515, 0);
			glEnd();
			glBegin(GL_LINE_LOOP);                                           //el 2oqar 9
			glColor3f(0, 0, 0);
			glVertex3f(795, 515, 0);
			glVertex3f(795, 485, 0);
			glVertex3f(815, 485, 0);
			glVertex3f(815, 515, 0);
			glEnd();
			glBegin(GL_POLYGON);                                             //el 2oqar 10
			glColor3f(0.5, 0.5, 0.5);
			glVertex3f(835, 515, 0);
			glVertex3f(835, 485, 0);
			glVertex3f(855, 485, 0);
			glVertex3f(855, 515, 0);
			glEnd();
			glBegin(GL_LINE_LOOP);                                           //el 2oqar 10
			glColor3f(0, 0, 0);
			glVertex3f(835, 515, 0);
			glVertex3f(835, 485, 0);
			glVertex3f(855, 485, 0);
			glVertex3f(855, 515, 0);
			glEnd();
			glBegin(GL_POLYGON);                                             //window
			glColor3f(0, 0, 0);
			glVertex3f(30, 570, 0);
			glVertex3f(30, 430, 0);
			glVertex3f(220, 430, 0);
			glVertex3f(220, 570, 0);
			glEnd();
			glBegin(GL_LINE_LOOP);                                           // window
			glColor3f(0, 0, 0);
			glVertex3f(30, 570, 0);
			glVertex3f(30, 430, 0);
			glVertex3f(220, 430, 0);
			glVertex3f(220, 570, 0);
			glEnd();
			glBegin(GL_POLYGON);                                             //inner window
			glColor3f(1, 1, 1);
			glVertex3f(50, 550, 0);
			glVertex3f(50, 450, 0);
			glVertex3f(200, 450, 0);
			glVertex3f(200, 550, 0);
			glEnd();
			glBegin(GL_LINE_LOOP);                                           //inner window
			glColor3f(0, 0, 0);
			glVertex3f(50, 550, 0);
			glVertex3f(50, 450, 0);
			glVertex3f(200, 450, 0);
			glVertex3f(200, 550, 0);
			glEnd();
			glBegin(GL_LINES);                                           //inner line
			glColor3f(0, 0, 0);
			glVertex3f(125, 550, 0);
			glVertex3f(125, 450, 0);
			glEnd();
			glBegin(GL_POLYGON);                                             //el 2oqar 11
			glColor3f(0.5, 0.5, 0.5);
			glVertex3f(95, 515, 0);
			glVertex3f(95, 485, 0);
			glVertex3f(115, 485, 0);
			glVertex3f(115, 515, 0);
			glEnd();
			glBegin(GL_LINE_LOOP);                                           //el 2oqar 11
			glColor3f(0, 0, 0);
			glVertex3f(95, 515, 0);
			glVertex3f(95, 485, 0);
			glVertex3f(115, 485, 0);
			glVertex3f(115, 515, 0);
			glEnd();
			glBegin(GL_POLYGON);                                             //el 2oqar 12
			glColor3f(0.5, 0.5, 0.5);
			glVertex3f(135, 515, 0);
			glVertex3f(135, 485, 0);
			glVertex3f(155, 485, 0);
			glVertex3f(155, 515, 0);
			glEnd();
			glBegin(GL_LINE_LOOP);                                           //el 2oqar 12
			glColor3f(0, 0, 0);
			glVertex3f(135, 515, 0);
			glVertex3f(135, 485, 0);
			glVertex3f(155, 485, 0);
			glVertex3f(155, 515, 0);
			glEnd();
			glPushMatrix();
			glTranslated(step, 0, 0);
			glBegin(GL_POLYGON);                                                   //shield
			glColor3f(0.3, 1, 0.8);
			glVertex3f(0, 420, 0);
			glVertex3f(0, 370, 0);
			glVertex3f(200, 370, 0);
			glVertex3f(200, 420, 0);
			glEnd();
			glBegin(GL_LINE_LOOP);
			glColor3f(0, 0, 0);
			glVertex3f(0, 420, 0);
			glVertex3f(0, 370, 0);
			glVertex3f(200, 370, 0);
			glVertex3f(200, 420, 0);
			glEnd();
			glPopMatrix();
			glPushMatrix();
			glTranslated(-15, 0, 0);
			glBegin(GL_POLYGON);                                                   //apple
			glColor3f(1, 0, 0);
			glVertex3f(150, 150, 0);
			glVertex3f(150, 80, 0);
			glVertex3f(180, 60, 0);
			glVertex3f(220, 60, 0);
			glVertex3f(250, 80, 0);
			glVertex3f(250, 150, 0);
			glEnd();
			glBegin(GL_LINE_LOOP);
			glColor3f(0, 0, 0);
			glVertex3f(150, 150, 0);
			glVertex3f(150, 80, 0);
			glVertex3f(180, 60, 0);
			glVertex3f(220, 60, 0);
			glVertex3f(250, 80, 0);
			glVertex3f(250, 150, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glColor3f(0, 1, 0);
			glVertex3f(196, 150, 0);
			glVertex3f(220, 190, 0);
			glVertex3f(180, 180, 0);
			glEnd();
			glBegin(GL_LINE_LOOP);
			glColor3f(0, 0, 0);
			glVertex3f(196, 150, 0);
			glVertex3f(220, 190, 0);
			glVertex3f(180, 180, 0);
			glEnd();
			glPopMatrix();
			glPushMatrix();
			glTranslated(15, 0, 0);
			glBegin(GL_TRIANGLES);                                                        //carrot
			glColor3f(1, 0.6, 0);
			glVertex3f(750, 150, 0);
			glVertex3f(850, 150, 0);
			glVertex3f(800, 60, 0);
			glEnd();
			glBegin(GL_LINE_LOOP);
			glColor3f(0, 0, 0);
			glVertex3f(750, 150, 0);
			glVertex3f(850, 150, 0);
			glVertex3f(800, 60, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glColor3f(0, 1, 0);
			glVertex3f(750, 150, 0);
			glVertex3f(750, 170, 0);
			glVertex3f(775, 160, 0);
			glVertex3f(800, 170, 0);
			glVertex3f(825, 160, 0);
			glVertex3f(850, 170, 0);
			glVertex3f(850, 150, 0);
			glEnd();
			glBegin(GL_LINE_LOOP);
			glColor3f(0, 0, 0);
			glVertex3f(750, 150, 0);
			glVertex3f(750, 170, 0);
			glVertex3f(775, 160, 0);
			glVertex3f(800, 170, 0);
			glVertex3f(825, 160, 0);
			glVertex3f(850, 170, 0);
			glVertex3f(850, 150, 0);
			glEnd();
			glBegin(GL_TRIANGLES);
			glColor3f(0, 0, 0);
			glVertex3f(800, 120, 0);
			glVertex3f(790, 110, 0);
			glVertex3f(810, 110, 0);
			glVertex3f(190, 110, 0);
			glVertex3f(200, 100, 0);
			glVertex3f(210, 110, 0);
			glEnd();
			glBegin(GL_LINES);
			glColor3f(0, 0, 0);
			glVertex3f(790, 90, 0);
			glVertex3f(800, 100, 0);
			glVertex3f(800, 100, 0);
			glVertex3f(810, 90, 0);
			glEnd();
			glPopMatrix();
			glBegin(GL_POLYGON);                                                         //health bars
			glColor3f(1, 1, 1);
			glVertex3f(630, 590, 0);
			glVertex3f(630, 615, 0);
			glVertex3f(930, 615, 0);
			glVertex3f(930, 590, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glColor3f(0, 1, 0);
			glVertex3f(630, 590, 0);
			glVertex3f(630, 615, 0);
			glVertex3f(healthbarx1, 615, 0);
			glVertex3f(healthbarx1, 590, 0);
			glEnd();
			glBegin(GL_LINE_LOOP);
			glColor3f(0, 0, 0);
			glVertex3f(630, 590, 0);
			glVertex3f(630, 615, 0);
			glVertex3f(930, 615, 0);
			glVertex3f(930, 590, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glColor3f(1, 1, 1);
			glVertex3f(400, 590, 0);
			glVertex3f(400, 615, 0);
			glVertex3f(100, 615, 0);
			glVertex3f(100, 590, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glColor3f(0, 1, 0);
			glVertex3f(healthbarx2, 590, 0);
			glVertex3f(healthbarx2, 615, 0);
			glVertex3f(100, 615, 0);
			glVertex3f(100, 590, 0);
			glEnd();
			glBegin(GL_LINE_LOOP);
			glColor3f(0, 0, 0);
			glVertex3f(400, 590, 0);
			glVertex3f(400, 615, 0);
			glVertex3f(100, 615, 0);
			glVertex3f(100, 590, 0);
			glEnd();
			glBegin(GL_POLYGON);                                            //power bars
			glColor3f(1, 1, 1);
			glVertex3f(10, 20, 0);
			glVertex3f(40, 20, 0);
			glVertex3f(40, 180, 0);
			glVertex3f(10, 180, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glColor3f(1, 1, 1);
			glVertex3f(960, 20, 0);
			glVertex3f(990, 20, 0);
			glVertex3f(990, 180, 0);
			glVertex3f(960, 180, 0);
			glEnd();
			glBegin(GL_LINE_LOOP);
			glColor3f(0, 0, 0);
			glVertex3f(10, 20, 0);
			glVertex3f(40, 20, 0);
			glVertex3f(40, 180, 0);
			glVertex3f(10, 180, 0);
			glEnd();
			glBegin(GL_LINE_LOOP);
			glColor3f(0, 0, 0);
			glVertex3f(960, 20, 0);
			glVertex3f(990, 20, 0);
			glVertex3f(990, 180, 0);
			glVertex3f(960, 180, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glColor3f(0.6, 0, 0.6);
			glVertex3f(10, 20, 0);
			glVertex3f(40, 20, 0);
			glVertex3f(40, c, 0);
			glVertex3f(10, c, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glColor3f(0.6, 0, 0.6);
			glVertex3f(960, 20, 0);
			glVertex3f(990, 20, 0);
			glVertex3f(990, d, 0);
			glVertex3f(960, d, 0);
			glEnd();
			glPushMatrix();
			glColor3f(0.5, 0.8, 1);
			glTranslated(167, 119, 0);
			GLUquadric* c = gluNewQuadric();
			gluDisk(c, 5, 20, 50, 50);
			glPopMatrix();
			glPushMatrix();
			glColor3f(0.5, 0.8, 1);
			glTranslated(207, 119, 0);
			GLUquadric* cd = gluNewQuadric();
			gluDisk(cd, 5, 20, 50, 50);
			glPopMatrix();
			glPushMatrix();
			glColor3f(1, 1, 1);
			glTranslated(186, 82, 0);
			GLUquadric* cdd = gluNewQuadric();
			gluDisk(cdd, 5, 15, 50, 50);
			glPopMatrix();
			glPushMatrix();
			glColor3f(0.5, 1, 0.1);
			glTranslated(796, 130, 0);
			GLUquadric* cddd = gluNewQuadric();
			gluDisk(cddd, 5, 15, 50, 50);
			glPopMatrix();
			glPushMatrix();
			glColor3f(0.5, 1, 0.1);
			glTranslated(830, 130, 0);
			GLUquadric* cdddd = gluNewQuadric();
			gluDisk(cdddd, 5, 15, 50, 50);
			glPopMatrix();
			glPushMatrix();
			glTranslated(x, y, 0);                                                             //seed
			glColor3f(0, 0, 0);
			glTranslated(255, 80, 0);
			GLUquadric* seed = gluNewQuadric();
			gluDisk(seed, 0, 15, 50, 50);
			glPopMatrix();
			glPushMatrix();
			glTranslated(-r, q, 0);
			glPushMatrix();                                                                     //leaf
			glBegin(GL_TRIANGLES);
			glColor3f(0.2, 0.7, 0.2);
			glVertex3f(760, 65, 0);
			glVertex3f(780, 65, 0);
			glVertex3f(770, 85, 0);
			glEnd();
			glPopMatrix();
			glBegin(GL_LINE_LOOP);
			glColor3f(0, 0, 0);
			glVertex3f(760, 65, 0);
			glVertex3f(780, 65, 0);
			glVertex3f(770, 85, 0);
			glEnd();
			glPopMatrix();
			print(300, 400, "FRUITS");
			print(600, 400, "VEGETABLES");
			print(480, 400, "VS");
			print(220, 595, "APPLE");
			print(745, 595, "CARROT");
			print(255, 50, "SEED");
			print(715, 50, "LEAF");
			print(140, 30, applecondition);
			print(740, 30, carrotmsg);
		}
		else {
			if (healthbarx2 == 100) {
				glBegin(GL_POLYGON);
				glColor3f(1, 0, 0);
				glVertex3f(0, 620, 0);
				glColor3f(0, 0, 1);
				glVertex3f(1000, 620, 0);
				glColor3f(1, 1, 0.2);
				glVertex3f(1000, 0, 0);
				glColor3f(0.5, 0, 0.5);
				glVertex3f(0, 0, 0);
				glEnd();
				print(400, 310, "Carrot Wins The Game");
				print(400, 290, "Thank You For Playing My Game");
				print(850, 20, "Created By ARK");
			}
			if (healthbarx1 == 630) {
				glBegin(GL_POLYGON);
				glColor3f(1, 0, 0);
				glVertex3f(0, 620, 0);
				glColor3f(0, 0, 1);
				glVertex3f(1000, 620, 0);
				glColor3f(1, 1, 0.2);
				glVertex3f(1000, 0, 0);
				glColor3f(0.5, 0, 0.5);
				glVertex3f(0, 0, 0);
				glEnd();
				print(400, 310, "Apple Wins The Game");
				print(400, 290, "Thank You For Playing My Game");
				print(850, 20, "Created By ARK");
			}
		}
	}
	glutPostRedisplay();
	glFlush();
}
void anim() {
	p0[0] = 0;
	p0[1] = 0;
	p1[0] = 81;
	p1[1] = 248;
	p2[0] = 104;
	p2[1] = 307;
	p3[0] = 122;
	p3[1] = 40;

	p4[0] = 0;
	p4[1] = 0;
	p5[0] = 0;
	p5[1] = 297;
	p6[0] = 53;
	p6[1] = 417;
	p7[0] = 136;
	p7[1] = 253;

	p8[0] = 0;
	p8[1] = 0;
	p9[0] = 54;
	p9[1] = 495;
	p10[0] = 451;
	p10[1] = 552;
	p11[0] = 421;
	p11[1] = 54;

	p12[0] = 0;
	p12[1] = 0;
	p13[0] = 100;
	p13[1] = 500;
	p14[0] = 499;
	p14[1] = 508;
	p15[0] = 551;
	p15[1] = 75;

	wing = wing + 5;
	if (step < 2000 && flag == true) {
		step = step + 0.5;
		if (step == 2000) {
			flag = false;
		}
	}
	if (step <= 2000 && flag == false) {
		step = step - 0.5;
		if (step == -1000) {
			flag = true;
		}
	}
	mouse2();
	glutPostRedisplay();
}
void main(int argc, char** argr) {
	glutInit(&argc, argr);
	glutInitWindowSize(1000, 620);
	glutInitWindowPosition(150, 150);
	glutCreateWindow("fruits vs vegetables");
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	gluOrtho2D(0.0, 1000, 0.0, 620);
	glutDisplayFunc(Display);
	glutIdleFunc(anim);
	glLineWidth(4.0);
	sndPlaySound(TEXT("eating.wav"), SND_LOOP | SND_ASYNC);
	glutMouseFunc(mouse1);
	glutMainLoop();
}


