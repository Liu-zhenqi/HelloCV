# 语雀文件
## 第一周
[实践任务](https://www.yuque.com/liubaibai-ffmn8/rwbhv3/wsy1fr9kduwaa0fh)
[Git版本控制](https://www.yuque.com/liubaibai-ffmn8/rwbhv3/iavv7pxf1qpshb6x)
[Linux安装，配置及入门操作（有vim）](https://www.yuque.com/liubaibai-ffmn8/rwbhv3/qtxuw0twsm5meb4g)
## 第二周
[实践任务](https://www.yuque.com/liubaibai-ffmn8/rwbhv3/mcfg2mlck0fylo6g)
[cmake](https://www.yuque.com/liubaibai-ffmn8/rwbhv3/aamayv5qvw5vpxkg)
[docker](https://www.yuque.com/liubaibai-ffmn8/rwbhv3/ymudmqs8snoyfvzl)
## 第三周
[实践任务](https://www.yuque.com/liubaibai-ffmn8/rwbhv3/pgu0bmr70wpgx2vt?singleDoc# 《2025211255 刘振齐 第三周 OpenCV 实践报告 )
[学习笔记](https://www.yuque.com/liubaibai-ffmn8/rwbhv3/pm70ntd4urgw0iu6?singleDoc# 《第三周 OpenCV 学习报告》)
# 项目介绍
## 项目结构
|--Traffictrack/
        |---------colorTrack.cpp
        |---------trafficTrack,cpp
        |---------CMakeLists.txt
        |---------result.avi
        |---------opencv小测试/
        |		|--------TrafficLight.mp4
        |		|--------输出示例.avi
        |		|--------GreenAndRed.png
        |		|--------red.png
        |----------build/
 
## 所需要的配置
1. cmake 3.10及以上
2. C++17及以上
3. 安装OpenCV
## 介绍
1. 本程序会识别红绿灯，并用**相应颜色**矩形框圈出，用相应颜色的英文单词在视频的左上角表示出来
2. 本程序会输出一个结果result.avi,并保存到相应目录当中。
3. 其中colorTrack.cpp用于找到红色和绿色的HSV值。（CMakeLists中没有包含该程序）。

