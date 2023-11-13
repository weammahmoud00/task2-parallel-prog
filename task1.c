#include <stdio.h>
#ifndef __cplusplus
#include <stdbool.h>
#include <string.h>
#endif

// char firstName;
// char lastName;
// char username;
// char password;
// int age;
union Flag
{
    int int_flag;
    bool bool_flag;
};

struct save
{
    char firstName;
    char lastName;
    char username;
    char password;
    int age;
    union Flag flag;
};

void signup()
{
    char firstName[10];
    char lastName[10];
    char username[15];
    char password;
    int age;

    printf("Enter your first name: ");
    scanf("%s", firstName);
    printf("Enter your last name: ");
    scanf("%s", lastName);
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);
    printf("Enter your age: ");
    scanf("%d", age);

    union Flag flag;
    printf("Enter a flag (0/1, true/false): ");
    scanf("%d", &flag.int_flag);
    if (flag.int_flag == 0)
    {
        flag.bool_flag = false;
    }
    else
    {
        flag.bool_flag = true;
    }

    struct save u;
    FILE *file;
    file = fopen("save.txt", "a");

    if (file != NULL)
    {
        struct save user;
        strcpy(user.username, username);
        strcpy(user.password, password);
        user.flag = flag;
        fprintf(file, "%s %s %d\n", user.username, user.password, user.flag.int_flag);
        fclose(file);
        printf("User registered successfully.\n");
        printf("Username: %s\n", user.username);
        printf("Password: %s\n", user.password);
    }
    else
    {
        printf("Error: Unable to open file for writing.\n");
    }

    // printf("Enter your first name: ");
    // scanf("%s", &firstName);
    // printf("Enter your last name: ");
    // scanf("%s", &lastName);
    // printf("Enter your username: ");
    // scanf("%s", &username);
    // printf("Enter your password: ");
    // scanf("%s", &password);
    // printf("Enter your age: ");
    // scanf("%d", &age);

    // fprintf(save,&firstName );
    // fprintf(&us, sizeof(us), 1, save);

    // fwrite(&u, 1, sizeof(u), store);
    // fclose(store);

    // fprintf(store, "%s %s %s %s %d %s\n", &u.firstName, &u.lastName, &u.username, &u.password, &u.age, &data.active.isActive);
    // printf("you signed up succesfully, now sign in");
    // getch();
    // system("CLS");
    // login();
}

int login()
{
    bool flag_active = false;
    // union Flag Flag;
    // struct save u;

    FILE *file = fopen("users.txt", "r");
    if (file != NULL)
    {
        struct save user;

        while (fscanf(file, "%s %s %d", user.username, user.password, &user.flag.int_flag) != EOF)
        {
            if (user.flag.int_flag == 1 || user.flag.bool_flag == true)
            {
                flag_active = true;
                break;
            }
        }

        fclose(file);

        if (!flag_active)
        {
            printf("All user accounts are currently inactive. Please contact an administrator.\n");
            return;
        }
    }
    else
    {
        printf("Error: Unable to open file for reading.\n");
        return;
    }

    char username[10];
    char password[10];

    printf("enter your username : ");
    scanf("%s", username);
    // if (username < 5)
    // {
    //     printf("error, username should be atleast 6 characters ");
    //     login();
    // }
    // else if (username > 15)
    // {
    //     printf("error, username shouldnt exceed 15 characters ");
    //     login();
    // }

    printf("enter your password : ");
    scanf("%s", password);

    file = fopen("users.txt", "r");
    if (file != NULL)
    {
        struct save user;

        while (fscanf(file, "%s %s %d", user.username, user.password, &user.flag.int_flag) != EOF)
        {
            if (strcmp(username, user.username) == 0 && strcmp(password, user.password) == 0)
            {
                if (user.flag.int_flag == 1 || user.flag.bool_flag == true)
                {
                    printf("Login successful. Welcome, %s!\n", username);
                }
                else
                {
                    printf("Your account is not active. Please contact an administrator.\n");
                }
                fclose(file);
                return;
            }
        }

        fclose(file);

        printf("Invalid username or password. Please try again.\n");
    }
    else
    {
        printf("Error: Unable to open file for reading.\n");
    }

    // while (fread(&u, 1, sizeof(u), store))
    // {
    //     // if (strcmp(username, &username) == 0 && strcmp(password, &password) == 0)

    //     if (strcmp(username, u.username) == 0 && strcmp(password, u.password) == 0)
    //     {
    //         // printf("you signed in succesfully");
    //         if (data.active.isActive == 1 || data.active.isActive == 'T')
    //         {
    //             printf("you signed in succesfully");
    //         }
    //         else
    //         {
    //             printf("you can not sign in!");
    //         }
    //     }
    //     else
    //     {
    //         printf("some credintials arent correct");
    //     }
    // }

    // printf("you signed in succesfully");

    // fclose(store);

    // if (username == username && password == password)
    // {
    //     printf("you signed in succesfully");
    // }
    // else
    // {
    //     (" some credintials arent correct");
    // }
}

int main()
{
    // union Data data;
    // struct save u;
    int inorup;
    printf("type 0 to login OR type 1 to sign up\n");
    scanf("%d", &inorup);
    if (inorup == 0)
    {
        system("CLS");
        login();
    }
    else if (inorup == 1)
    {
        system("CLS");
        signup();
    }
}
