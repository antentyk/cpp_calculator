CXX = g++
FLAGS = -g -pthread -std=c++14

OBJ_DIR = obj
BIN_DIR = bin
PRG_NAME = calculator

EXCEPTIONS_DIR = Exceptions
TOKENS_DIR = Tokens
TOKENS_PARSER_DIR = TokensParser
TOKENS_STREAM_DIR = TokensStream

OBJ = $(addprefix $(OBJ_DIR)/,\
Tokens.o\
TokenType.o\
)
OBJ += $(addprefix $(OBJ_DIR)/, TokensParser.o)
OBJ += $(addprefix $(OBJ_DIR)/, TokensStream.o)
OBJ += $(addprefix $(OBJ_DIR)/, main.o)

all: init $(PRG_NAME)

init :
	mkdir -p $(OBJ_DIR)
	mkdir -p $(BIN_DIR)

$(PRG_NAME): $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) -o $(BIN_DIR)/$(PRG_NAME)

$(OBJ_DIR)/%.o: %.cpp $(EXCEPTIONS_DIR)/*.h
	$(CXX) $(FLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(TOKENS_DIR)/%.cpp $(TOKENS_DIR)/*.h
	$(CXX) $(FLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(TOKENS_PARSER_DIR)/%.cpp $(TOKENS_PARSER_DIR)/*.h
	$(CXX) $(FLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(TOKENS_STREAM_DIR)/%.cpp $(TOKENS_STREAM_DIR)/*.h
	$(CXX) $(FLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR) 