#version 330 core


out vec4 FragColor;

in vec3 color;

in vec2 textureCoordinates;


uniform sampler2D texture0;

uniform vec3 cameraPosition;

uniform bool useTexture;

void main()
{

if (useTexture) {
FragColor = texture(texture0, textureCoordinates);
}
else {
FragColor = vec4(color, 1.0f);
}


};