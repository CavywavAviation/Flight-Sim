#include "include.hpp"
#include "graphics.hpp"

double noise(int x, int y) {
  static double prevHeight = 0;
  std::mt19937 gen(x);
  std::uniform_int_distribution<int> dis(-9, 9);
  int a = dis(gen);
  std::mt19937 gen2(y);
  std::uniform_int_distribution<int> dis2(-9, 9);
  int b = dis2(gen2);
  int height = prevHeight + a + b;
  prevHeight = height;
  return height;
}

double Point::distance(const Point& p) {
  return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
}
Point& Point::operator+=(const Vector& v) {
  x += v.i; 
  y += v.j; 
  z += v.k; 
  return *this;
}
Point Point::operator+(const Vector& v) {
  return Point(x + v.i, y + v.j, z + v.k);
}
Vector Point::operator-(const Point& p) {
  return Vector(x - p.x, y - p.y, z - p.z);
}

Vector Vector::operator+(const Point& p) {
  Vector t(p);
  return Vector(i + t.i, j + t.j, k + t.k);
}
Vector Vector::operator+(const Vector& v) {
  return Vector(i + v.i, j + v.j, k + v.k);
}
Vector& Vector::operator+=(const Vector& v) {
  i += v.i;
  j += v.j;
  k += v.k;
  return *this;
}
Vector Vector::operator-(const Vector& v) {
  return Vector(i - v.i, j - v.j, k - v.k);
}
Vector& Vector::operator-=(const Vector& v) {
  i -= v.i;
  j -= v.j;
  k -= v.k;
  return *this;
}
Vector Vector::operator-() {
  return Vector(-i, -j, -k);
}
double Vector::dot(const Vector& v) {
  return i * v.i + j * v.j + k * v.k;
}
Vector Vector::cross(const Vector& v) {
  return Vector(j * v.k - k * v.j, k * v.i - i * v.k, i * v.j - j * v.i);
}
double Vector::magnitude() {
  return sqrt(i*i + j*j + k*k);
}
Vector Vector::operator*(double d) {
  return Vector(i*d, j*d, k*d);
}
Vector Vector::operator/(double d) {
  return Vector(i/d, j/d, k/d);
}

Plane::Plane(Point p1, Point p2, Point p3) {
  Vector n = (p2 - p1).cross(p3 - p1);
  a = n.i;
  b = n.j;
  c = n.k;
  d = -(Vector(p1).dot(n));
}
