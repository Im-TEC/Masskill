/*
*     Made By TEC1204
*     Discord: TEC1204#8384
*     Date: 3/30/20
*     Time: 5:43
*     Game: Forward Assault
*     Device: IOS
*/

struct Vector3{
  float x;
  float y;
  float z;

  Vector3();
  Vector3(float x, float y, float z);
  ~Vector3();
};

Vector3::Vector3() {}
Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
Vector3::~Vector3() {}
