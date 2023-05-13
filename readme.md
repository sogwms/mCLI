# mCLI

mCLI 源自一个项目中的实现文本交互功能子模块, 想让其更通用, 故有了 mCLI, ing...

mCLI 以面向接口&对象的方式设计，整个系统分为三个模块 commander, controller, editor，且以接口的形式约定了各个模块的职责(功能). 其中 commander 负责接收命令并执行(同时存储命令等)；controller 负责调度支持一些特殊指令 (比如 '&&')；editor 则负责和用户交互 (比如 响应用户的编辑操作，退格，删改等)(同时存储用户的输入)

## Running

```
xmake 

xmake run test
```