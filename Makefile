CFLAGS=-Wall -g

obj= main.o utils.o listfunctions.o 
NP_List_Problems: $(obj) listheader.h
	cc -o NP_List_Problems $(obj) listheader.h
	@echo "make complete"

main.o:
utils.o:
listfunctions.o:

clean:
	rm -f cd $(obj)
	@echo "cd, $(obj) files are removed"

