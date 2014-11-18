// Arkadiusz Gabrys qe83mepi
// Agnieszka Zacher by57zeja

varying vec3 N; 
varying vec4 P;

uniform vec4 LightSource;  // updated each draw call 
uniform vec4 Color;  // updated each draw call
 
void main() {

    vec3 L = normalize((LightSource - P).xyz);
    vec3 E = normalize(P.xyz);
    vec3 R = reflect(L, N);

    // phong
    int s = 3;
    vec4 diff, spec, ambient;
    float dotPr = 0.0;
    
    // diff
    dotPr = dot(N, L);
    if (dotPr < 0.0)
    {
        dotPr = 0.0;
    }
    diff = Color * dotPr;

    // spec
    dotPr = dot(E, R);
    if (dotPr < 0.0)
    {
        dotPr = 0.0;
    }

    spec = vec4(1.0) * pow(dotPr, s);

    // ambient
    ambient = Color * 0.2;

        gl_FragColor = ambient + diff + spec;
}
