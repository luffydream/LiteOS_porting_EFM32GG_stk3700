# LiteOS_porting_EFM32GG_stk3700
HuaWeiLiteOS_EFM32GG_stk3700
根据@Supowang 提供的建议，修改了一些地方，很容易就将LiteOS porting到了GIANT GECKO STARTER KIT上。
基本步骤：
      1/建立一个新的工程，配置software compaonet的时候，可以选择把库文件，驱动文件和芯片的startup文件加入工程中。这样就可以很方便的调用官方已经写好的驱动。
      2/把kernel和平台相关文件加入到工程中，这个可以按照官方文档来添加就可以。
      3/配置工程，包括C/C++选项下面的include paths和SCT文件修改，这个也可以参考我附件中的工程。
      4/修改los_hwi.c和los_hw_tick.c的函数名称来适配底层的CMSIS库函数的名称。具体可以参考文件中的修改。
