```c++
    //函数的凹凸性质可以使用打表制作图像，或者求导判断

    //三分本质：每次消去不可能存在正确答案的区间

    int l = 0, r = n;//取值范围
    //浮点型凹函数
    while (r - l > 1e-7)
    {
        int lmid = l + (r - l) / 3.0, rmid = r - (r - l) / 3.0;
        if (f(lmid) > f(rmid))l = lmid;
        else r = rmid;
    }
    //浮点型凸函数
    while (r - l > 1e-7)
    {
        int lmid = l + (r - l) / 3.0, rmid = r - (r - l) / 3.0;
        if (f(lmid) < f(rmid))l = lmid;//>改为<
        else r = rmid;
    }
    //整型凹函数
    while (l < r)
    {
        int lmid = l + (r - l) / 3, rmid = r - (r - l) / 3;
        if (f(lmid) > f(rmid))l = lmid + 1;
        else r = rmid - 1;
    }
    //整型凸函数
    while (l < r)
    {
        int lmid = l + (r - l) / 3, rmid = r - (r - l) / 3;
        if (f(lmid) < f(rmid))l = lmid + 1;
        else r = rmid - 1;
    }
```
#三分法
必须保证这个单峰函数的峰值左右两边都是单调的。