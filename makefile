# Fil placeringer
CC = g++
CFLAGS = -std=c++17
WX_CONFIG = external/wxWidgets/build/wx-config  # Sørg for at dette er den rigtige sti
LDFLAGS = $(shell $(WX_CONFIG) --libs)  # Brug wx-config til at hente linker flags
CXXFLAGS = $(shell $(WX_CONFIG) --cxxflags)  # Brug wx-config til at hente kompilatorflags

# Filnavn på mål
TARGET = my_program

# Standard mål
all: $(TARGET)

# Byg MainFrame.o fra MainFrame.cpp
MainFrame.o: MainFrame.cpp
	$(CC) $(CXXFLAGS) $(CFLAGS) -c MainFrame.cpp -o MainFrame.o

# Byg App.o fra App.cpp
App.o: App.cpp
	$(CC) $(CXXFLAGS) $(CFLAGS) -c App.cpp -o App.o

# Link objektfilerne og lav programmet
$(TARGET): MainFrame.o App.o
	$(CC) $(CFLAGS) MainFrame.o App.o -o $(TARGET) $(LDFLAGS)

# Konfiguration og bygning af wxWidgets
wxwidgets:
	mkdir -p external/wxWidgets/build
	cd external/wxWidgets/build && ../configure --with-opengl --disable-shared
	make -C external/wxWidgets/build

# Ryd op
clean:
	rm -f $(TARGET) MainFrame.o App.o
	make -C external/wxWidgets/build clean || true
