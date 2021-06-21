/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** common
*/

#ifndef COMMON_H_
#define COMMON_H_

#define MAX_NAME_LENGTH 32
#define MAX_DESCRIPTION_LENGTH 255
#define MAX_BODY_LENGTH 512
#define UNUSED __attribute__((unused))

enum command{
    UNKNOWN,
    HELP,
    LOGIN,
    LOGOUT,
    USERS,
    USER,
    SEND,
    MESSAGES,
    SUBSCRIBED,
    SUBSCRIBE,
    UNSUBSCRIBE,
    USE,
    CREATE,
    LIST,
    INFO
};

enum useType {
    GLOBAL,
    TEAM,
    CHANNEL,
    THREAD
};

typedef struct info_s {
    char uuidUser[37];
    char uuidTeam[37];
    char uuidChannel[37];
    char uuidThread[37];
} __attribute__((packed)) info_t;

typedef struct user_s {
    char uuid[37];
    char username[MAX_NAME_LENGTH];
    int status;
    int fd;
} __attribute__((packed)) user_t;

typedef struct messages_s {
    char message[MAX_BODY_LENGTH];
    char uuid_sender[37];
    char uuid_receiver[37];
    time_t timestamp;
} __attribute__((packed)) messages_t;

typedef struct team_s {
    char uuid[37];
    char user_uuid[37];
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
} __attribute__((packed)) team_t;

typedef struct channel_s {
    char uuid[37];
    char team_uuid[37];
    char name[MAX_NAME_LENGTH];
    char team_name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
} __attribute__((packed)) channel_t;

typedef struct thread_s {
    char uuid[37];
    char user_uuid[37];
    char team_uuid[37];
    char channel_uuid[37];
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    time_t timestamp;
} __attribute__((packed)) thread_t;

typedef struct reply_s {
    char uuid[37];
    char user_uuid[37];
    char team_uuid[37];
    char channel_uuid[37];
    char thread_uuid[37];
    char body[MAX_DESCRIPTION_LENGTH];
    time_t timestamp;
} __attribute__((packed)) reply_t;

typedef struct link_s {
    char user_uuid[37];
    char team_uuid[37];
} __attribute__((packed)) link_t;

#endif /* !COMMON_H_ */
