#ifndef _BIN_H_COURSE_WORK
#define _BIN_H_COURSE_WORK

#define MAX_PATH_LEN 4096       // максимальная длина пути
#define MAX_FILENAME_LEN 256    // максимальная длина имени файла

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <time.h>
#include <stdbool.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

void println();                                         // функция вывод линии из '-' я
void print_menu();                                      // функция вывода меню на экран
void input_option(char *option);                        // функция ввода опции с проверками
void list_bin_files();                                  // функция вывод всех файлов, находящихся в корзине
void restore_file_from_bin(const char *filename);                // функция восстановления файла из корзины
void log_new_file(const char *path_name, const char *new_path);  // функция восстановления файла из корзины
void input_file_path(char *new_path);                   // функция для ввода имени файла
void compute_paths();                                   // функция для вычисления путей
int find_last_slash(const char *s, int start_pos);      // функции для нахождения первого и последнего '/', начиная с start_pos
int find_first_slash(const char *s, int start_pos);
int check_bin_log();                                    // функция для проверки заполненности корзины
void delete_line_from_binlog_file(const char *dest);    // функция для удаления строки из файла журнала
void delete_file_forever(const char *filename);         // функция для перманентного удаленного файла
void init();                                            // функция для инициализации данных
void clear_bin_log();                                   // функция для очистки файла журнала
void clear_bin();                                       // функция для очистки корзины

void input_full_or_relative_file_path(char *old_path_name, char *path_name,
                                      char *new_path);                // функция для ввода полного или относительного пути
void put_file_to_bin_with_checks(char *old_path_name, char *new_path);// функция для перемещения файла в корзину с проверками


#endif
