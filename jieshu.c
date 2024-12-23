#include "jieshu.h"
#include "book.h"

void jeishu()
{
    int id;
    int bookID;
    printf("请输入会员号码：");
    scanf("%d",&id);
    if(huiyuanpanduan(id) != 1)  {
        printf("\n非会员！"); 
        return;
    }// 判断是否为会员

    printf("\n请输入书本号码：");
    scanf("%d",&bookID);

    
    if(serch_jieshu(bookID) == -1){
    printf("错误！没有该图书！");
    return;
    }
    
    if(serch_jieshu(bookID) == 0){  
    printf("借书没成功！图书已经被借走了！");
    return;
    }
    if(serch_jieshu(bookID) == 1)  
    printf("该图书可以借阅，是否借阅？(y/n)：\n");
    char c;
    scanf("%c",&c);
    if(c == 'y'){
        library[bookID].isBorrowed = 1;
        printf("借阅成功！");
    }
    else return;

}
int serch_jieshu(int num)
{
    for(int i=0;i<BookCount;i++){
        if(library[i].id == num){
            if(Book[i].isBorrowed == 1) return 1;//  可以借
            else return 0;// 图书被借走了，失败        
        }
        else return -1;//  没有该图书
    }
}

int huiyuanpanduan(int id)
{
    for(int i=0;i<HuiyuanCount;i++){
        if(Huiyuan[i].id == id){
            return 1;
        }
        else return -1;//  非会员
    }
}
