# CircularSplashScreen
采用QT5写的滚动环形登录界面。
重点是  "background-color: qconicalgradient(cx:0.5, cy:0.5, angle:0, stop:{STOP1} rgba(255, 0, 127, 0), stop:{STOP2} rgba(85, 170, 255, 255))"这里产生一个扇形，
然后再套一个小一点的圆，形成环形。还有一个小技巧：	border-radius:135px;把这个值调成大小的一半，就会形成圆形。
![image](https://github.com/mecctor/CircularSplashScreen/blob/main/CircularSplash.png)
