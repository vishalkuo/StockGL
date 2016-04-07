#version 450 core
attribute vec2 coord2d;


void main(void)
{
   gl_Position = vec4(coord2d.x, coord2d.y,0, 1.0);
}