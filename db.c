typedef struct {
    char* buffer;
    size_t buffer_length;   // this is the size of the objects in memory.
    ssize_t input_length;   // this is the number of bytes read/written. We use signed
    // int to reserve negative numbers of indicating error conditions
} InputBuffer;


InputBuffer* new_input_buffer() {
    InputBuffer* input_buffer = (InputBuffer*)malloc(sizeof(InputBuffer));
    input_buffer->buffer = NULL;
    input_buffer->buffer_length = input_buffer->input_length = 0;
    return input_buffer;
}

void print_prompt() {   printf("db > ");    }

ssize_t getline(char **lineptr, size_t *n, FILE *stream);


int main(int argc, char* argv[]) {
    InputBuffer * input_buffer = new_input_buffer();
    while (true) {
        print_prompt();
        read_input(input_buffer);

        if(strcmp(input_buffer->buffer, ".exit") == 0) {
            close_input_buffer(input_buffer);
            exit(EXIT_SUCCESS);
        } else {
            printf("Unrecognized command '%s'.\n", input_buffer->buffer);
        }
    }
}
