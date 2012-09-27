FINAL = main.cc Button.cc
OUT = glCalc.o
REQ = main.cc Button.h 

linux: $(REQ)
	g++ -o $(OUT) $(FINAL) -I/usr/X11R6/include -L/usr/X11R6/lib -lGL -lGLEW -lglut -lGLU

mac: $(REQ)
	g++ -o $(OUT) $(FINAL) -I/opt/local/include -L/opt/local/lib -framework OpenGL -framework GLUT -lGLEW

Button.o: Button.h
	echo "Not Yet!"

clean:
	rm *.o
