# QT编程练习

## 练习清单

- QT01: 准备Linux系统Qt开发环境；
- QT02: Qt配置文件；
- QT08: 串口Terminal
- QT10: JSON及Tree Model/View


## 练习QT01 准备Linux系统Qt开发环境

- 安装QT集成环境；
- 编写一个窗口程序显示Hello world；
- 在打印语句之前设置断点，调试模式运行，断点中断时查看各变量此刻取值；
- 单步运行，查看变量当前取值的变化情况；

## 练习QT02 QT配置文件

- 点击按钮时弹出文件对话框，提示用户选择一个文件；
- 用QSettings记录打开路径；
- 关闭程序，重新打开；
- 再次点击按钮，文件对话框默认打开上次目录；

## 练习QT08 串口Terminal

不用线程实现以下功能：

- 编写一个窗口程序，包含配置栏和文本框
- 在配置栏里选择串口、指定波特率；
- 连接一块嵌入式linux开发板的串口；
- 将串口收到的linux系统输出显示在文本框里；
- 文本框最下面一行显示命令行提示符，显示用户的键盘输入；
- 用户按回车后，将输入的命令发给串口；

## 练习QT10 JSON及Tree Model/View

- 读取用户指定的json内容 （只有json object，没有array）；
- 将json内容显示到tree view上，用tree model管理数据；
- 点击某一个条目后，弹出对话框显示“parent.son.property = value”，其中parent、son、property、value为json文件中具体对象、子对象、属性名字或取值；
