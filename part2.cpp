#include <GL/glut.h>
#include <iostream>
using namespace std;

double tx = 0;
double ty = 0;
double tz = 0;

double scale = 0.1f;

double kc = 0;

void init() {
  glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
  glEnable(GL_DEPTH_TEST);
}

struct point{
	double x;
	double y;
	double z;
	
	void nhan(point &p, double Sx){
		p.x *=Sx;
		p.y *=Sx;
		p.z *=Sx;
	}
	
	void tong(point &p, double tx, double ty, double tz){
		p.x +=tx;
		p.y +=ty;
		p.z +=tz;
	}
	
	void biendangOx(point &p, double kc){
		p.x += kc;
	}
	
	void biendangOy(point &p, double kc){
		p.y += kc;
	}
	
	void biendangOz(point &p, double kc){
		p.z +=kc;
	}
};

point A;
point B;
point C;
point D;

point a;
point b;
point c;
point d;

void reset(){
	tx =0;
	ty=0;
	tz=0;
	
	scale = 1.0f;
}

void biendangtheoOx(){
	A.biendangOx(A, kc);
	B.biendangOx(B, kc);
//	C.biendangOx(C, kc);
//	D.biendangOx(D, kc);
	
	a.biendangOx(a, kc);
	b.biendangOx(b, kc);
//	c.biendangOx(c, kc);
//	d.biendangOx(d, kc);
}

void biendangtheoOy(){
	A.biendangOx(A, kc);
	B.biendangOy(B, kc);
//	C.biendangOy(C, kc);
//	D.biendangOy(D, kc);
	
	a.biendangOy(a, kc);
	b.biendangOy(b, kc);
//	c.biendangOy(c, kc);
//	d.biendangOy(d, kc);
}

void biendangtheoOz(){
	A.biendangOx(A, kc);
	B.biendangOz(B, kc);
//	C.biendangOz(C, kc);
//	D.biendangOz(D, kc);
	
	a.biendangOz(a, kc);
	b.biendangOz(b, kc);
//	c.biendangOz(c, kc);
//	d.biendangOz(d, kc);
}

void tinhtien(){
	A.tong(A, tx, ty, tz);
	B.tong(B, tx, ty, tz);
	C.tong(C, tx, ty, tz);
	D.tong(D, tx, ty, tz);
	
	a.tong(a, tx, ty, tz);
	b.tong(b, tx, ty, tz);
	c.tong(c, tx, ty, tz);
	d.tong(d, tx, ty, tz);
	
	cout<<"c: "<<c.x<<" "<<c.y<<" "<<c.z<<endl;
	
}

void tyle(){
	A.nhan(A, scale);
	B.nhan(B, scale);
	C.nhan(C, scale);
	D.nhan(D, scale);
	
	a.nhan(a, scale);
	b.nhan(b, scale);
	c.nhan(c, scale);
	d.nhan(d, scale);
}

void khoitao(){
	A.x = -0.5;
	A.y = 0.5;
	A.z = 0.5;
	
	B.x = 0.5;
	B.y = 0.5;
	B.z = 0.5;
	
	C.x = 0.5;
	C.y = -0.5;
	C.z = 0.5;
	
	D.x = -0.5;
	D.y = -0.5;
	D.z = 0.5;
	
	a.x = -0.5;
	a.y = 0.5;
	a.z = -0.5;
	
	b.x = 0.5;
	b.y = 0.5;
	b.z = -0.5;
	
	c.x = 0.5;
	c.y = -0.5;
	c.z = -0.5;
	
	d.x = -0.5;
	d.y = -0.5;
	d.z = -0.5;
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

  // Thuc hien các phép bien doi


  // Ve h?nh lap phuong
  	glBegin(GL_QUADS); // Ve mat truoc
	glColor3f(1.0f, 0.0f, 0.0f); // Màu do
	glVertex3f(B.x, B.y, B.z); // ?inh trên bên phai
	glVertex3f(A.x, A.y, A.z); // ?inh trên bên trái
	glVertex3f(D.x, D.y, D.z); // ?inh duoi bên trái
	glVertex3f(C.x, C.y, C.z); // ?inh duoi bên phai
	glEnd();
	
	glBegin(GL_QUADS); // Ve mat sau
	glColor3f(0.0f, 1.0f, 0.0f); // Màu xanh lá
	glVertex3f(a.x, a.y, a.z); // ?inh duoi bên phai
	glVertex3f(b.x, b.y, b.z); // ?inh duoi bên trái
	glVertex3f(c.x, c.y, c.z); // ?inh trên bên trái
	glVertex3f(d.x, d.y, d.z); // ?inh trên bên phai
	glEnd();
	
	glBegin(GL_QUADS); // Ve mat trái
	glColor3f(0.0f, 0.0f, 1.0f); // Màu xanh duong
	glVertex3f(A.x, A.y, A.z); // ?inh trên bên trái
	glVertex3f(a.x, a.y, a.z); // ?inh trên bên phai
	glVertex3f(d.x, d.y, d.z); // ?inh duoi bên phai
	glVertex3f(D.x, D.y, D.z); // ?inh duoi bên trái
	glEnd();
	
	glBegin(GL_QUADS); // Ve mat phai
	glColor3f(1.0f, 1.0f, 0.0f); // Màu vàng
	glVertex3f(b.x, b.y, b.z); // ?inh trên bên phai
	glVertex3f(B.x, B.y, B.z); // ?inh trên bên trái
	glVertex3f(C.x, C.y, C.z); // ?inh duoi bên trái
	glVertex3f(c.x, c.y, c.z); // ?inh duoi bên phai
	glEnd();
	
	glBegin(GL_QUADS); // Ve mat trên
	glColor3f(1.0f, 0.0f, 1.0f); // Màu hong
	glVertex3f(a.x, a.y, a.z); // ?inh trên bên trái
	glVertex3f(b.x, b.y, b.z); // ?inh trên bên phai
	glVertex3f(B.x, B.y, B.z); // ?inh duoi bên phai
	glVertex3f(A.x, A.y, A.z); // ?inh duoi bên trái
	
	glBegin(GL_QUADS); // Ve mat duoi
	glColor3f(0.0f, 1.0f, 1.0f); // Màu xanh nuoc bien
	glVertex3f(d.x, d.y, d.z); // ?inh trên bên trái
	glVertex3f(c.x, c.y, c.z); // ?inh trên bên phai
	glVertex3f(C.x, C.y, C.z); // ?inh duoi bên phai
	glVertex3f(D.x, D.y, D.z); // ?inh duoi bên trái
	glEnd();
	
	glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height) {
  if (height == 0) height = 1;
  GLfloat aspect = (GLfloat)width / (GLfloat)height;
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f, aspect, 0.1f, 100.0f);
//  glOrtho(5.0, 5.0, 5.0);
}

void keyboard(unsigned char key, int x, int y) {
  switch (key) {
    case 'w':  // Di chuyen lên trên theo truc y
	  reset();
	  ty = 0.1f;
      tinhtien();
      break;
    case 's':  // Di chuyen xuong duoi theo truc y
      reset();
      ty = -0.1f;
      tinhtien();
      break;
    case 'a':  // Di chuyen sang trái theo truc x
      reset();
      tx = -0.1f;
      tinhtien();
      break;
    case 'd':  // Di chuyen sang phai theo truc x
      reset();
      tx = 0.1f;
      tinhtien();
      break;
    case 'q':  // Di chuyen theo truc z
      reset();
      tz = -0.1f;
      tinhtien();
      break;
    case 'e':  // Di chuyen theo truc z
      reset();
      tz = 0.1f;
      tinhtien();
      break;
    case '+':  // Tang ty le
      reset();
      scale = 2.0f;
      tyle();
      break;
    case '-':  // Giam ty le
      reset();
      scale = 0.5f;
      tyle();
      break;
	case 'x':
		kc = 1.0f;
		biendangtheoOx();
		break;
	case 'y':
		kc = 1.0f;
		biendangtheoOy();
		break;
	case 'z':
		kc = 1.0f;
		biendangtheoOz();
		break;
	case 'j':
		kc = -1.0f;
		biendangtheoOx();
		break;
	case 'k':
		kc = -1.0f;
		biendangtheoOy();
		break;
	case 'l':
		kc = -1.0f;
		biendangtheoOz();
		break;
    case 27:   // ESC key
      exit(0);
      break;
    default:
      break;
  }
  glutPostRedisplay();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(50, 50);
  glutCreateWindow("3D Transformations");
  khoitao();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  init();
  glutMainLoop();
  return 0;
}

