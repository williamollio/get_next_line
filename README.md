# get_next_line

Goals : This project will not only allow you to add a very convenient function to your collection, but it will also allow you to learn a highly interesting new concept in C programming: static variables.

Calling your function get_next_line in a loop will then allow you to read the text available on the file descriptor one line at a time until the end of it.

Subject PDF: https://github.com/williamollio/get_next_line/blob/main/subject/get_next_line.pdf

# Clone
Open a terminal and run following command:
```
git clone <repository url>
```
# Run
Go to the created repository and then into the folders ```test```. You can run the following command to test my project :

```
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1 ../get_next_line.c ../get_next_line_utils.c main.c  && ./a.out
```
# Explanations

The read function uses the value of the ```BUFFER_SIZE``` variable, which is initialized at the compilation. Therefore, the flag -D BUFFER_SIZE=xx has to be used, otherwise its value by default is 42.

Feel free to modificate the value of the buffer or the file where it reads from. 
