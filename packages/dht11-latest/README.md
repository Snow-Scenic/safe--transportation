# DHT11 数字温湿度传感器

## 简介

DHT11 数字温湿度传感器是一款含有已校准数字信号输出的温湿度复合传感器。它应用专用的数字模块采集技术和温湿度传感技术，确保产品具有枀高的可靠性与卓越的长期稳定性。传感器包括一个电阻式感湿元件和一个 NTC 测温元件，幵与一个高性能 8 位单片机相连接，对外提供单总线通讯接口。更多 DHT11 的使用说明请参考 DHT11 厂家数据手册。

## 注意事项

DHT11 是采用单总线通讯的传感器，本软件包采用 GPIO 模拟单总线时序。DHT11 的一次完整读时序需要 20ms，时间过长，故无法使用关中断或者关调度的方式实现独占 CPU 以保证时序完整正确。因此可能出现读取数据失败的情况，请用户注意。


