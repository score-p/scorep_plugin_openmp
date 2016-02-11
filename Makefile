PLUGIN_NAME=OpenMP
#MP_PLUGIN_NAME=$(PLUGIN_NAME)MP
TP_PLUGIN_NAME=$(PLUGIN_NAME)TP
CC = gcc

all:
#	$(CC) -c -fPIC -fopenmp $(MP_PLUGIN_NAME).c $(INC) -o lib$(MP_PLUGIN_NAME).so.o `scorep-config --cppflags`
#	$(CC) -shared -Wl,-soname,lib$(MP_PLUGIN_NAME) -o lib$(MP_PLUGIN_NAME).so lib$(MP_PLUGIN_NAME).so.o
	$(CC) -c -fPIC -fopenmp $(TP_PLUGIN_NAME).c $(INC) -o lib$(TP_PLUGIN_NAME).so.o `scorep-config --cppflags`
	$(CC) -shared -Wl,-soname,lib$(TP_PLUGIN_NAME) -o lib$(TP_PLUGIN_NAME).so lib$(TP_PLUGIN_NAME).so.o
#	$(CC) -shared -Wl,--no-whole-archive,-soname,lib$(MP_PLUGIN_NAME) -o lib$(MP_PLUGIN_NAME).so lib$(MP_PLUGIN_NAME).so.o

install: all
	mkdir -p $(HOME)/install/scorep/lib/plugins/
	cp lib$(TP_PLUGIN_NAME).so $(HOME)/install/scorep/lib/plugins/
#	cp lib$(MP_PLUGIN_NAME).so lib$(TP_PLUGIN_NAME).so $(HOME)/install/scorep/lib/plugins/

clean:
	rm -f lib$(TP_PLUGIN_NAME).so lib$(TP_PLUGIN_NAME).so.o
#	rm -f lib$(MP_PLUGIN_NAME).so lib$(MP_PLUGIN_NAME).so.o lib$(TP_PLUGIN_NAME).so lib$(TP_PLUGIN_NAME).so.o
