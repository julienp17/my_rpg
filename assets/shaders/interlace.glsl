#version 120

uniform sampler2D texture;
uniform float amount = .1;
uniform float density = 10.;
uniform float speed = 1.;
uniform bool interlace = true;
uniform float time = 0.;
uniform float screen_coords_y = 1080.;

void main()
{
    vec2 pixel_xy = gl_TexCoord[0].xy;
    float offset = amount * cos(pixel_xy.y * density + speed * time);
    if (interlace && mod(screen_coords_y, 2.) > 1.) offset *= -1.;
    pixel_xy.x += offset;
    pixel_xy.x = mod(pixel_xy.x, 1.);

	vec4 pixel = texture2D(texture, pixel_xy.xy);
	gl_FragColor = gl_Color * pixel;
}