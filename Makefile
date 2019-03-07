All:
	gcc -Wall -c src/tableVis.c -o objFiles/tableVis.o
	gcc -Wall -c src/mainApp.c -o objFiles/mainApp.o
	gcc objFiles/tableVis.o objFiles/mainApp.o -o program