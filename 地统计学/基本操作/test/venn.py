from matplotlib_venn import venn2, venn2_circles, venn2_unweighted
from matplotlib_venn import venn3, venn3_circles
import matplotlib.pyplot as plt

# 样例数据
Group1 = ['a','b','c','f','g','i','p','q']
Group2 = ['b','e','f','h','k','q','r','s','t','u','v','z']
Group3 = ['c','e','g','h','j','k','o','q','z']

#可视化绘制
plt.rcParams['font.family'] = ["Times New Roman"]
fig, ax = plt.subplots(figsize=(5,3),dpi=110)
vee2 = venn2([set(Group1), set(Group2)],set_labels=("Group1", "Group2"),
      set_colors=("#0073C2FF", "#EFC000FF"), alpha = 0.8,ax=ax)
venn2_circles([set(Group1), set(Group2)], linestyle="--", linewidth=2, color="black",ax=ax)

# 定制化设置:设置字体属性
# for text in vee2.set_labels:
#     text.set_fontsize(15);
# for text in vee2.subset_labels:
#     text.set_fontsize(16)
#     text.set_fontweight("bold")
# ax.text(.8,-.1,'\nVisualization by DataCharm',transform = ax.transAxes,
#         ha='center', va='center',fontsize = 8,color='black')
# plt.title("Example Of venn2() and venn2_circles()",size=15,fontweight="bold",
#          backgroundcolor="#868686FF",color="black",style="italic")
plt.show()
pass
fig, ax = plt.subplots(figsize=(5,3),dpi=110)
vd3=venn3([set(Group1),set(Group2),set(Group3)],
          set_labels=("Group1","Group2","Group3"),
          set_colors=('#0073C2FF','#EFC000FF',"#CD534CFF"),
          alpha = 0.8,ax=ax)
venn3_circles([set(Group1), set(Group2),set(Group3)], linestyle="--", linewidth=2, color="black",ax=ax)
# 定制化设置
for text in vd3.set_labels:
    text.set_fontsize(15);
    text.set_fontweight("bold")
for text in vd3.subset_labels:
    text.set_fontsize(15)
    text.set_fontweight("bold")
ax.text(.8,-.1,'\nVisualization by DataCharm',transform = ax.transAxes,
        ha='center', va='center',fontsize = 9,color='black')
plt.title("Example Of venn3() and venn3_circles()",fontweight="bold",fontsize=15,
          pad=30,backgroundcolor="#868686FF",color="black",style="italic")
plt.show()