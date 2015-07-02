# True-color plasma fractal using non-recursive algorithm
# FB - 201003287
import random
from PIL import Image
imgx = 512
imgy = 512
image = Image.new("RGB", (imgx, imgy))
mx = imgx - 1
my = imgy - 1
f = 2.0 # roughness

image.putpixel((0, 0), (random.randint(0, 255),
	random.randint(0, 255),
	random.randint(0, 255)))
image.putpixel((mx, 0), (random.randint(0, 255),
	random.randint(0, 255),
	random.randint(0, 255)))
image.putpixel((mx, my), (random.randint(0, 255),
	random.randint(0, 255),
	random.randint(0, 255)))
image.putpixel((0, my), (random.randint(0, 255),
	random.randint(0, 255),
	random.randint(0, 255)))
j = -1
while True:
j += 1
			j2 = 2 ** j
				jx = float(mx) / j2
					jy = float(my) / j2
						if jx < 1 and jy < 1: break
								for i in range(j2):
									y0 = i * jy
													y1 = y0 + jy
															y = y0 + jy / 2.0        
																	for k in range(j2):
																		x0 = k * jx
																								x1 = x0 + jx
																											x = x0 + jx / 2.0

																																a = image.getpixel((x0, y0))
																																			b = image.getpixel((x1, y0))
																																						c = image.getpixel((x0, y1))
																																									d = image.getpixel((x1, y1))

																																												image.putpixel((x, y), ((a[0] + b[0] + c[0] + d[0]) / 4.0,
																																													(a[1] + b[1] + c[1] + d[1]) / 4.0,
																																													(a[2] + b[2] + c[2] + d[2]) / 4.0))
																																												image.putpixel((x, y0), ((a[0] + b[0]) / 2.0 + jx * (random.random() - .5) * f,
																																													(a[1] + b[1]) / 2.0 + jx * (random.random() - .5) * f,
																																													(a[2] + b[2]) / 2.0 + jx * (random.random() - .5) * f))
																																												image.putpixel((x0, y), ((a[0] + c[0]) / 2.0 + jy * (random.random() - .5) * f,
																																													(a[1] + c[1]) / 2.0 + jy * (random.random() - .5) * f,
																																													(a[2] + c[2]) / 2.0 + jy * (random.random() - .5) * f))
																																												image.putpixel((x1, y), ((b[0] + d[0]) / 2.0 + jy * (random.random() - .5) * f,
																																													(b[1] + d[1]) / 2.0 + jy * (random.random() - .5) * f,
																																													(b[2] + d[2]) / 2.0 + jy * (random.random() - .5) * f)) 
																																												image.putpixel((x, y1), ((c[0] + d[0]) / 2.0 + jx * (random.random() - .5) * f,
																																													(c[1] + d[1]) / 2.0 + jx * (random.random() - .5) * f,
																																													(c[2] + d[2]) / 2.0 + jx * (random.random() - .5) * f))

																																												image.save("plasma3.png", "PNG")
