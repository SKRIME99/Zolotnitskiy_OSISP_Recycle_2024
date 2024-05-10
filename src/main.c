
#include <stdio.h>
#include <stdlib.h>

#include "binlib.h"

int main()
{
    init();
    char option;
    while(true)
    {
        input_option(&option);
        switch (option)
        {
            case 'l':
            {
                list_bin_files();
                break;
            }
            case 'd':
            {
                if(check_bin_log() == -1) break;
                char path_name[MAX_PATH_LEN];
                printf("input name of file you want to delete permanently:\n");
                input_file_path(path_name);
                delete_file_forever(path_name);
                break;
            }
            case 'c':
            {
                if(check_bin_log() == -1) break;
                clear_bin_log();
                clear_bin();
                printf("bin was succesfully cleared\n");
                println();
                break;
            }
            case 'p':
            {
                char old_path_name[MAX_PATH_LEN] = {0};
                char path_name[MAX_FILENAME_LEN] = {0};
                char new_path[MAX_PATH_LEN] = {0};
                input_full_or_relative_file_path(old_path_name, path_name,
                                                 new_path);
                put_file_to_bin_with_checks(old_path_name, new_path);
                println();
                break;
            }

            case 'r':
            {
                if(check_bin_log() == -1) break;
                char new_path[MAX_PATH_LEN] = {0};
                printf("input name of file you want to restore:\n");
                input_file_path(new_path);
                restore_file_from_bin(new_path);
                println();
                break;
            }
            case 'm':
            {
                print_menu();
                break;
            }
            case 'q':
            {
                exit(0);
                break;
            }
        }
    }
    return 0;
}
