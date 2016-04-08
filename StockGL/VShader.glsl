#version 450 core
attribute vec2 coord2d;
varying vec4 frag_color;

void main(void)
{
   gl_Position = vec4(coord2d.x, coord2d.y,0, 1.0);
   frag_color= vec4(coord2d.xy / 2.0 + 0.5, 1, 1);
}