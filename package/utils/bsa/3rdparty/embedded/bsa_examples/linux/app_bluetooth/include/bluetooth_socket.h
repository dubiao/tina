#ifndef __BLUETOOTH_SOCKET_H__
#define __BLUETOOTH_SOCKET_H__

#include <string.h>
#include <pthread.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <unistd.h>
#include <interface.h>

enum {
    BT_CMD_PLAY = 0xf1,
    BT_CMD_PAUSE,
    BT_CMD_PRE,
    BT_CMD_NEXT,
    BT_CMD_PICK_UP,
    BT_CMD_HUNG_UP,
    BT_CMD_TRANSACT_EVENT,
    
    BT_CMD_DO_TEST,
};

enum BT_EVENT{
	  BT_AVK_CONNECTED_EVT = 0, 
	  BT_AVK_DISCONNECTED_EVT = 1, 
    BT_AVK_START_EVT = 2,       /* stream data transfer started */
    BT_AVK_STOP_EVT = 3,	       /* stream data transfer stopped */
    BT_AUDIO_OPEN_REQ_EVT = 4,
    BT_HS_CONNECTED_EVT = 5,
    BT_HS_DISCONNECTED_EVT = 6,
    BT_HS_AUDIO_OPEN_EVT = 7,
    BT_HS_AUDIO_CLOSE_EVT =8,
};


typedef struct bt_data{
    int data1;
    int data2;
}bt_data;

typedef void (tBtCallback)(BT_EVENT event);

class c_bt : public c_interface
{
public:
    c_bt();
    virtual ~c_bt();
private:
    tBtCallback *pBtCb;

protected:
    void onTransact(request_t* request,data_t* data);

public:    
    int avk_play();
    int avk_pause();
    int avk_previous();
    int avk_next();
    int hs_pick_up();
    int hs_hung_up();
    void set_callback(tBtCallback *pCb);
    void do_test();
};

class s_bt : public s_interface
{
public:
    s_bt();
    virtual ~s_bt();

protected:
    void onTransact(request_t* request,data_t* data);

public:
    int do_transact_event(BT_EVENT event);
};


#endif /* __BLUETOOTH_CLIENT_H__ */