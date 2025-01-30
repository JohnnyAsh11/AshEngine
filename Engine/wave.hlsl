#ifdef GL_ES
precision mediump float;
#endif

uniform float time;

uniform vec2 resolution;

#define speed 0.2
#define freq 0.7
#define amp 0.5
#define phase 0.5

void main() 
{
	vec2 p = (gl_FragCoord.xy / resolution.xy) - 0.5;
	
	float sx = (amp) * 1.2 * sin( 9.0 * (freq) * (p.x-phase) - 3.5 * (speed) * time);
	
	float dy = 100./ ( 60. * abs(4.9*p.y - sx - 1.2));
	
	gl_FragColor = vec4((p.x + 0.05) * dy, 0.2 * dy, dy, 2.0);
}
