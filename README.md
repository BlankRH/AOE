# AOE

### loop
- detect_joystick
- stop_laser
- detect_light
- gameOver ? game_over

### control_laser
- activate_laser: 射击， 记录上次射击秒数
- stop_laser: 现在秒数大于上次射击秒数+射击持续时间 ？ 关闭

### control_motor
- control_motor: 如果摇杆左偏： 向左，右偏向右，中心：不懂
- set_motor_pwm: 控制转速/方向

### detect_joystick
- detect_joystick：
    + 获取摇杆指示
    + 如果游戏未结束
        * 控制方向
        * 控制射击
    + 如果游戏结束
        * 两人射击，重新开始
- joystick: 获取coordinates
- test_print_joystick

### detect_light
- detect_light：获取当前光照强度，大于limit: 游戏结束，更新玩家状态

### game_over
- game_over: 输/赢/平局，等待重新开始
- game_restart: 重置
- reset: 重置参数

火线红色
地线黑
摇杆1：x轴白色，y轴灰色
摇杆2：x轴黄色，y轴橙色
马达：蓝/紫
laser: 电源绿，ground棕

