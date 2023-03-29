#include <stdio.h>
#include "renderer.h"
#include "vec3.h"

//image resolution
const int image_width = 256;
const int image_height = 256;

int main(){

	//printf("P3\n%d %d\n255\n", image_width, image_height);
	frender(image_width, image_height);

    vec3 a = {1.0, 1.0, 1.0};
    vec3 b = {1.0, 1.0, 1.0};

    vec3 c = vadd(a,b);
    a = vmul(c, 3);
    //const double x = vdot(a,c);
  //  printf("%f %f %f %f\n", c.x, c.y, c.z, x);

	return 0;
}

