// Arkadiusz Gabrys qe83mepi
// Agnieszka Zacher by57zeja

uniform float Time;  // updated each frame by the application

uniform mat4 MVP;  // updated each draw call
uniform mat4 MV;  // updated each draw call 
uniform mat3 NormalMatrix;  // updated each draw call
 
uniform vec4 LightSource;  // updated each draw call
 
varying vec3 N;
varying vec4 P;

void main() {

	 
	 //TODO: Compute view vector, normal and vertex position 
     
	N = normalize(NormalMatrix * gl_Normal);
	P = MV * gl_Vertex;
 
        gl_Position = MVP * gl_Vertex;
}
