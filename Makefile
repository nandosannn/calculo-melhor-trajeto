# Nome do compilador
CXX = g++

# Flags de compilação
CXXFLAGS = -Wall -std=c++11 -I$(INCDIR)

# Diretórios
SRCDIR = src
INCDIR = include
OBJDIR = obj

# Nome do executável
TARGET = main

# Arquivos de origem e objetos
SOURCES = $(wildcard $(SRCDIR)/**/*.cpp) $(wildcard $(SRCDIR)/**/**/*.cpp) main.cpp
OBJECTS = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SOURCES))

# Regra padrão (primeira regra é o alvo padrão)
all: $(TARGET)

# Regra para criar o executável
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

# Regra para criar os arquivos objeto
$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	@mkdir -p $(dir $@)  # Cria o diretório de objetos necessário
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para criar o diretório de objetos
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Regra para limpar o projeto
clean:
	rm -rf $(OBJDIR) $(TARGET)

# Phony targets (alvos que não são arquivos)
.PHONY: all clean
