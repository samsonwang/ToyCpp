
#include <cstring>
#include <cstdio>

extern int x;

class Point {
public:
    Point(float x_, float y_)
        : x(x_),
          y(y_) {

    }

    /* 需要注意的是不能将函数命名为 float x() const;
       因为这样会和成员变量的名称重复。
    */
    float getX() const {
        return x;
    }

    void setX() const {
        //        x = 1;
    }
/*
  加上这个虚函数用于测试虚指针存放的位置
  virtual void setY(float y_) {
  y = y_;
  }
*/
    //private:
public:
    float x;
    float y;
};

int main(int argc, char* argv[]) {

    Point pt(1.0, 1.0);
    float ptx = pt.getX();

    printf("ptx = %f\n", ptx);

    printf("&Point::x = %p\n", &Point::x);
    printf("&Point::y = %p\n", &Point::y);

    printf("&pt = %p\n", &pt);
    printf("&pt.x = %p\n", &pt.x);
    printf("&pt.y = %p\n", &pt.y);

    return 0;
}
