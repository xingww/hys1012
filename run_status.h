#ifndef RUN_STATUS_H
#define RUN_STATUS_H

enum Running {
    UNSTART = 0,
    PAUSE = 1,
    RUNNING = 2,
    STOP = 3
};

enum FormType {
    ACTIVE,     // 主动界面
    PASSIVE     // 被动界面
};

#endif // RUN_STATUS_H
