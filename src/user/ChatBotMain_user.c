#include "ChatBotMain_user.h"

/**
 * 用户自定义实现
 * 此文件只生成一次，可自由修改
 */

// 在此添加自定义实现

// 表情状态枚举
typedef enum
{
    EMOTION_NORMAL = 0,
    EMOTION_HAPPY,
    EMOTION_SAD,
    EMOTION_SURPRISED,
    EMOTION_MAX
} EmotionState;

// 眼睛目标状态结构
typedef struct {
    int width;
    int height;
    int x;
    int y;
} EyeState;

// 当前表情状态
static EmotionState current_emotion = EMOTION_NORMAL;
static EmotionState target_emotion = EMOTION_NORMAL;

// 表情名称数组
static const char *emotion_names[] = {
    "Normal",
    "Happy",
    "Sad",
    "Surprised"
};

// 眨眼动画状态
static int blink_step = 0;
static int blink_frame = 0;
static int blink_cooldown = 0;  // 眨眼冷却计数器
#define BLINK_CLOSE_FRAMES 6   // 闭眼动画帧数
#define BLINK_OPEN_FRAMES 6    // 睁眼动画帧数
#define BLINK_COOLDOWN_FRAMES 120  // 冷却时间（约2秒，60fps）

// 开心表情动画状态
static int happy_step = 0;
static int happy_frame = 0;
static int happy_blink_count = 0;  // 快速眨眼计数
#define HAPPY_SQUINT_FRAMES 16      // 眯眼动画帧数
#define HAPPY_BLINK_CLOSE_FRAMES 4  // 快速眨眼闭眼帧数
#define HAPPY_BLINK_OPEN_FRAMES 4   // 快速眨眼睁眼帧数
#define HAPPY_BLINK_TOTAL 4         // 总共眨眼次数
#define HAPPY_BROW_BOUNCE_FRAMES 10  // 眉毛跳动周期帧数

// 伤心表情动画状态
static int sad_step = 0;
static int sad_frame = 0;
static int sad_blink_cooldown = 0;  // 眨眼冷却计数器
#define SAD_DROOP_FRAMES 15         // 眼睛下垂动画帧数
#define SAD_BLINK_CLOSE_FRAMES 12   // 缓慢眨眼闭眼帧数（比正常慢2倍）
#define SAD_BLINK_OPEN_FRAMES 12    // 缓慢眨眼睁眼帧数
#define SAD_BLINK_COOLDOWN_FRAMES 120  // 眨眼冷却时间

// 惊讶表情动画状态
static int surprised_step = 0;
static int surprised_frame = 0;
static int surprised_blink_cooldown = 0;
#define SURPRISED_STAGE1_FRAMES 40   // 第一阶段：微微睁大
#define SURPRISED_STAGE2_FRAMES 80   // 第二阶段：继续睁大+抖动
#define SURPRISED_BLINK_CLOSE_FRAMES 10  // 缓慢眨眼闭眼帧数
#define SURPRISED_BLINK_OPEN_FRAMES 10   // 缓慢眨眼睁眼帧数
#define SURPRISED_BLINK_COOLDOWN_FRAMES 120  // 眨眼冷却时间（约2秒）
#define SURPRISED_SHAKE_AMPLITUDE 3  // 抖动幅度（像素）


// 线性插值函数
static int lerp(int start, int end, int step, int total_steps)
{
    return start + (end - start) * step / total_steps;
}

// 正常表情动画
static void emotion_normal_animation(void)
{
    // 正常表情：平滑眨眼动画
    if (blink_step == 0)
    {
        // 正常状态，等待触发眨眼
        gui_rect_set_size((gui_rounded_rect_t *)hg_rect_leftEyeOuter, 90, 110);
        gui_rect_set_size((gui_rounded_rect_t *)hg_rect_rightEyeOuter, 90, 110);
        gui_rect_set_position((gui_rounded_rect_t *)hg_rect_leftEyeOuter, 123, 105);
        gui_rect_set_position((gui_rounded_rect_t *)hg_rect_rightEyeOuter, 265, 105);
        
        // 眉毛恢复正常位置
        gui_arc_set_position(hg_arc_left, 168, 151);
        gui_arc_set_position(hg_arc_right, 309, 151);
        gui_arc_set_radius(hg_arc_left, 80);
        gui_arc_set_radius(hg_arc_right, 80);
        
        // 冷却计数器递增
        blink_cooldown++;
        
        // 冷却时间到达后，随机触发眨眼
        if (blink_cooldown >= BLINK_COOLDOWN_FRAMES && rand() % 100 < 50)
        {
            blink_step = 1;
            blink_frame = 0;
            blink_cooldown = 0;
        }
    }
    else if (blink_step == 1)
    {
        // 闭眼阶段：高度从 110 逐渐变小到 20
        blink_frame++;
        int target_height = 20;
        int original_height = 110;
        int current_height = lerp(original_height, target_height, blink_frame, BLINK_CLOSE_FRAMES);
        int y_offset = (original_height - current_height) / 2;  // 保持垂直居中
        
        gui_rect_set_size((gui_rounded_rect_t *)hg_rect_leftEyeOuter, 90, current_height);
        gui_rect_set_size((gui_rounded_rect_t *)hg_rect_rightEyeOuter, 90, current_height);
        gui_rect_set_position((gui_rounded_rect_t *)hg_rect_leftEyeOuter, 123, 105 + y_offset);
        gui_rect_set_position((gui_rounded_rect_t *)hg_rect_rightEyeOuter, 265, 105 + y_offset);
        
        // 眉毛跟着向下移动（移动幅度为眼睛收缩的1/3）
        int brow_offset = y_offset / 3;
        gui_arc_set_position(hg_arc_left, 168, 151 + brow_offset);
        gui_arc_set_position(hg_arc_right, 309, 151 + brow_offset);
        
        if (blink_frame >= BLINK_CLOSE_FRAMES)
        {
            blink_step = 2;
            blink_frame = 0;
        }
    }
    else if (blink_step == 2)
    {
        // 睁眼阶段：高度从 20 逐渐恢复到 110
        blink_frame++;
        int target_height = 110;
        int closed_height = 20;
        int current_height = lerp(closed_height, target_height, blink_frame, BLINK_OPEN_FRAMES);
        int y_offset = (target_height - current_height) / 2;  // 保持垂直居中
        
        gui_rect_set_size((gui_rounded_rect_t *)hg_rect_leftEyeOuter, 90, current_height);
        gui_rect_set_size((gui_rounded_rect_t *)hg_rect_rightEyeOuter, 90, current_height);
        gui_rect_set_position((gui_rounded_rect_t *)hg_rect_leftEyeOuter, 123, 105 + y_offset);
        gui_rect_set_position((gui_rounded_rect_t *)hg_rect_rightEyeOuter, 265, 105 + y_offset);
        
        // 眉毛跟着向上恢复（移动幅度为眼睛收缩的1/3）
        int brow_offset = y_offset / 3;
        gui_arc_set_position(hg_arc_left, 168, 151 + brow_offset);
        gui_arc_set_position(hg_arc_right, 309, 151 + brow_offset);
        
        if (blink_frame >= BLINK_OPEN_FRAMES)
        {
            blink_step = 0;  // 回到正常状态
            blink_frame = 0;
        }
    }
}

// 开心表情动画
static void emotion_happy_animation(void)
{
    // 开心表情分为三个阶段：
    // 1. 眯眼阶段：眼睛高度从 110 逐渐变小到 40
    // 2. 快速眨眼阶段：在眯眼状态下快速眨眼 3 次
    // 3. 保持阶段：保持眯眼状态，眉毛持续跳动
    
    if (happy_step == 0)
    {
        // 阶段1：眯眼动画
        happy_frame++;
        int original_height = 110;
        int target_height = 40;
        int current_height = lerp(original_height, target_height, happy_frame, HAPPY_SQUINT_FRAMES);
        int y_offset = (original_height - current_height) / 2;  // 保持垂直居中
        
        gui_rect_set_size((gui_rounded_rect_t *)hg_rect_leftEyeOuter, 90, current_height);
        gui_rect_set_size((gui_rounded_rect_t *)hg_rect_rightEyeOuter, 90, current_height);
        gui_rect_set_position((gui_rounded_rect_t *)hg_rect_leftEyeOuter, 123, 105 + y_offset);
        gui_rect_set_position((gui_rounded_rect_t *)hg_rect_rightEyeOuter, 265, 105 + y_offset);
        
        // 眉毛向下移动
        int brow_offset = y_offset / 3;
        gui_arc_set_position(hg_arc_left, 168, 151 + brow_offset);
        gui_arc_set_position(hg_arc_right, 309, 151 + brow_offset);
        
        if (happy_frame >= HAPPY_SQUINT_FRAMES)
        {
            happy_step = 1;
            happy_frame = 0;
            happy_blink_count = 0;
        }
    }
    else if (happy_step == 1)
    {
        // 阶段2：快速眨眼（闭眼）
        happy_frame++;
        int squinted_height = 40;
        int blink_height = 10;
        int current_height = lerp(squinted_height, blink_height, happy_frame, HAPPY_BLINK_CLOSE_FRAMES);
        int y_offset = (110 - current_height) / 2;
        
        gui_rect_set_size((gui_rounded_rect_t *)hg_rect_leftEyeOuter, 90, current_height);
        gui_rect_set_size((gui_rounded_rect_t *)hg_rect_rightEyeOuter, 90, current_height);
        gui_rect_set_position((gui_rounded_rect_t *)hg_rect_leftEyeOuter, 123, 105 + y_offset);
        gui_rect_set_position((gui_rounded_rect_t *)hg_rect_rightEyeOuter, 265, 105 + y_offset);
        
        // 眉毛跳动
        int brow_bounce = y_offset / 3;
        gui_arc_set_position(hg_arc_left, 168, 151 + brow_bounce);
        gui_arc_set_position(hg_arc_right, 309, 151 + brow_bounce);
        
        if (happy_frame >= HAPPY_BLINK_CLOSE_FRAMES)
        {
            happy_step = 2;
            happy_frame = 0;
        }
    }
    else if (happy_step == 2)
    {
        // 阶段2：快速眨眼（睁眼）
        happy_frame++;
        int blink_height = 10;
        int squinted_height = 40;
        int current_height = lerp(blink_height, squinted_height, happy_frame, HAPPY_BLINK_OPEN_FRAMES);
        int y_offset = (110 - current_height) / 2;
        
        gui_rect_set_size((gui_rounded_rect_t *)hg_rect_leftEyeOuter, 90, current_height);
        gui_rect_set_size((gui_rounded_rect_t *)hg_rect_rightEyeOuter, 90, current_height);
        gui_rect_set_position((gui_rounded_rect_t *)hg_rect_leftEyeOuter, 123, 105 + y_offset);
        gui_rect_set_position((gui_rounded_rect_t *)hg_rect_rightEyeOuter, 265, 105 + y_offset);
        
        // 眉毛跳动（向下）
        int brow_bounce = y_offset / 3;
        gui_arc_set_position(hg_arc_left, 168, 151 + brow_bounce);
        gui_arc_set_position(hg_arc_right, 309, 151 + brow_bounce);
        
        if (happy_frame >= HAPPY_BLINK_OPEN_FRAMES)
        {
            happy_blink_count++;
            if (happy_blink_count >= HAPPY_BLINK_TOTAL)
            {
                happy_step = 3;  // 进入保持阶段
                happy_frame = 0;
            }
            else
            {
                happy_step = 1;  // 继续眨眼
                happy_frame = 0;
            }
        }
    }
    else if (happy_step == 3)
    {
        // 阶段3：保持眯眼状态，眉毛持续跳动
        happy_frame++;
        
        // 保持眯眼状态
        int squinted_height = 20;
        int y_offset = (110 - squinted_height) / 2;
        gui_rect_set_size((gui_rounded_rect_t *)hg_rect_leftEyeOuter, 90, squinted_height);
        gui_rect_set_size((gui_rounded_rect_t *)hg_rect_rightEyeOuter, 90, squinted_height);
        gui_rect_set_position((gui_rounded_rect_t *)hg_rect_leftEyeOuter, 123, 105 + y_offset);
        gui_rect_set_position((gui_rounded_rect_t *)hg_rect_rightEyeOuter, 265, 105 + y_offset);
        
        // 眉毛持续跳动
        int base_brow_y = 151 + y_offset / 3;
        int brow_bounce = (happy_frame % (HAPPY_BROW_BOUNCE_FRAMES * 2)) < HAPPY_BROW_BOUNCE_FRAMES ? -5 : 5;
        gui_arc_set_position(hg_arc_left, 168, base_brow_y + brow_bounce);
        gui_arc_set_position(hg_arc_right, 309, base_brow_y + brow_bounce);
        
        gui_fb_change();
    }
}

// 伤心表情动画
static void emotion_sad_animation(void)
{
    // 伤心表情分为三个阶段：
    // 1. 下垂阶段：眼睛缩小并向下移动，眉毛向下移动并拉平
    // 2. 缓慢眨眼阶段：在下垂状态下缓慢眨眼
    // 3. 保持阶段：保持下垂状态，偶尔缓慢眨眼
    
    if (sad_step == 0)
    {
        // 阶段1：下垂动画
        sad_frame++;
        int original_height = 110;
        int target_height = 80;
        int current_height = lerp(original_height, target_height, sad_frame, SAD_DROOP_FRAMES);
        
        // 眼睛宽度从 90 → 70（变窄）
        int original_width = 90;
        int target_width = 70;
        int current_width = lerp(original_width, target_width, sad_frame, SAD_DROOP_FRAMES);
        
        // 眼睛向下移动 10 像素
        int base_y_offset = (original_height - current_height) / 2;
        int down_offset = lerp(0, 10, sad_frame, SAD_DROOP_FRAMES);
        int total_y_offset = base_y_offset + down_offset;
        
        // X 偏移量保持眼睛居中
        int x_offset = (original_width - current_width) / 2;
        
        gui_rect_set_size((gui_rounded_rect_t *)hg_rect_leftEyeOuter, current_width, current_height);
        gui_rect_set_size((gui_rounded_rect_t *)hg_rect_rightEyeOuter, current_width, current_height);
        gui_rect_set_position((gui_rounded_rect_t *)hg_rect_leftEyeOuter, 123 + x_offset, 105 + total_y_offset);
        gui_rect_set_position((gui_rounded_rect_t *)hg_rect_rightEyeOuter, 265 + x_offset, 105 + total_y_offset);
        
        // 眉毛向下移动 60 像素
        int brow_offset = lerp(0, 60, sad_frame, SAD_DROOP_FRAMES);
        gui_arc_set_position(hg_arc_left, 168, 151 + brow_offset);
        gui_arc_set_position(hg_arc_right, 309, 151 + brow_offset);
        
        // 眉毛弧度拉平：增大半径 80 → 120，角度从 240-300度 → 260-280度
        int current_radius = lerp(80, 120, sad_frame, SAD_DROOP_FRAMES);
        gui_arc_set_radius(hg_arc_left, current_radius);
        gui_arc_set_radius(hg_arc_right, current_radius);
        
        float start_angle = 240.0f + (20.0f * sad_frame / SAD_DROOP_FRAMES);  // 240 → 260
        float end_angle = 300.0f - (20.0f * sad_frame / SAD_DROOP_FRAMES);    // 300 → 280
        gui_arc_set_start_angle(hg_arc_left, start_angle);
        gui_arc_set_end_angle(hg_arc_left, end_angle);
        gui_arc_set_start_angle(hg_arc_right, start_angle);
        gui_arc_set_end_angle(hg_arc_right, end_angle);

        
        if (sad_frame >= SAD_DROOP_FRAMES)
        {
            sad_step = 1;
            sad_frame = 0;
            sad_blink_cooldown = 0;
        }
        gui_fb_change();
    }
    else if (sad_step == 1)
    {
        // 阶段2：保持下垂状态，等待触发缓慢眨眼
        int drooped_height = 80;
        int drooped_width = 70;
        int y_offset = (110 - drooped_height) / 2 + 10;
        int x_offset = (90 - drooped_width) / 2;
        
        gui_rect_set_size((gui_rounded_rect_t *)hg_rect_leftEyeOuter, drooped_width, drooped_height);
        gui_rect_set_size((gui_rounded_rect_t *)hg_rect_rightEyeOuter, drooped_width, drooped_height);
        gui_rect_set_position((gui_rounded_rect_t *)hg_rect_leftEyeOuter, 123 + x_offset, 105 + y_offset);
        gui_rect_set_position((gui_rounded_rect_t *)hg_rect_rightEyeOuter, 265 + x_offset, 105 + y_offset);
        
        // 眉毛保持向下位置和拉平状态
        gui_arc_set_position(hg_arc_left, 168, 211);
        gui_arc_set_position(hg_arc_right, 309, 211);
        gui_arc_set_radius(hg_arc_left, 120);
        gui_arc_set_radius(hg_arc_right, 120);
        gui_arc_set_start_angle(hg_arc_left, 260.0f);
        gui_arc_set_end_angle(hg_arc_left, 280.0f);
        gui_arc_set_start_angle(hg_arc_right, 260.0f);
        gui_arc_set_end_angle(hg_arc_right, 280.0f);
        
        // 冷却计数器递增
        sad_blink_cooldown++;
        
        // 冷却时间到达后，随机触发缓慢眨眼
        if (sad_blink_cooldown >= SAD_BLINK_COOLDOWN_FRAMES && rand() % 100 < 25)
        {
            sad_step = 2;
            sad_frame = 0;
            sad_blink_cooldown = 0;
        }
    }
    else if (sad_step == 2)
    {
        // 阶段3：缓慢闭眼
        sad_frame++;
        int drooped_height = 80;
        int drooped_width = 70;
        int blink_height = 15;
        int current_height = lerp(drooped_height, blink_height, sad_frame, SAD_BLINK_CLOSE_FRAMES);
        int y_offset = (110 - current_height) / 2 + 10;
        int x_offset = (90 - drooped_width) / 2;
        
        gui_rect_set_size((gui_rounded_rect_t *)hg_rect_leftEyeOuter, drooped_width, current_height);
        gui_rect_set_size((gui_rounded_rect_t *)hg_rect_rightEyeOuter, drooped_width, current_height);
        gui_rect_set_position((gui_rounded_rect_t *)hg_rect_leftEyeOuter, 123 + x_offset, 105 + y_offset);
        gui_rect_set_position((gui_rounded_rect_t *)hg_rect_rightEyeOuter, 265 + x_offset, 105 + y_offset);
        
        // 眉毛保持向下位置和拉平状态
        gui_arc_set_position(hg_arc_left, 168, 211);
        gui_arc_set_position(hg_arc_right, 309, 211);
        gui_arc_set_radius(hg_arc_left, 120);
        gui_arc_set_radius(hg_arc_right, 120);
        gui_arc_set_start_angle(hg_arc_left, 260.0f);
        gui_arc_set_end_angle(hg_arc_left, 280.0f);
        gui_arc_set_start_angle(hg_arc_right, 260.0f);
        gui_arc_set_end_angle(hg_arc_right, 280.0f);
        
        if (sad_frame >= SAD_BLINK_CLOSE_FRAMES)
        {
            sad_step = 3;
            sad_frame = 0;
        }
    }
    else if (sad_step == 3)
    {
        // 阶段4：缓慢睁眼
        sad_frame++;
        int blink_height = 15;
        int drooped_height = 80;
        int drooped_width = 70;
        int current_height = lerp(blink_height, drooped_height, sad_frame, SAD_BLINK_OPEN_FRAMES);
        int y_offset = (110 - current_height) / 2 + 10;
        int x_offset = (90 - drooped_width) / 2;
        
        gui_rect_set_size((gui_rounded_rect_t *)hg_rect_leftEyeOuter, drooped_width, current_height);
        gui_rect_set_size((gui_rounded_rect_t *)hg_rect_rightEyeOuter, drooped_width, current_height);
        gui_rect_set_position((gui_rounded_rect_t *)hg_rect_leftEyeOuter, 123 + x_offset, 105 + y_offset);
        gui_rect_set_position((gui_rounded_rect_t *)hg_rect_rightEyeOuter, 265 + x_offset, 105 + y_offset);
        
        // 眉毛保持向下位置和拉平状态
        gui_arc_set_position(hg_arc_left, 168, 211);
        gui_arc_set_position(hg_arc_right, 309, 211);
        gui_arc_set_radius(hg_arc_left, 120);
        gui_arc_set_radius(hg_arc_right, 120);
        gui_arc_set_start_angle(hg_arc_left, 260.0f);
        gui_arc_set_end_angle(hg_arc_left, 280.0f);
        gui_arc_set_start_angle(hg_arc_right, 260.0f);
        gui_arc_set_end_angle(hg_arc_right, 280.0f);
        
        if (sad_frame >= SAD_BLINK_OPEN_FRAMES)
        {
            sad_step = 1;  // 回到保持状态
            sad_frame = 0;
        }
    }
}

// 惊讶表情动画
static void emotion_surprised_animation(void)
{
    // 惊讶表情分为三个阶段：
    // 1. 微微睁大：眼睛从 110 → 120
    // 2. 继续睁大+抖动：眼睛 120 → 135，眉毛上扬，左右抖动
    // 3. 达到最大+保持：眼睛和眉毛达到最大状态并保持
    
    if (surprised_step == 0)
    {
        // 阶段1：眼睛微微睁大
        surprised_frame++;
        
        // 眼睛高度 110 → 120
        int original_height = 110;
        int target_height = 120;
        int current_height = lerp(original_height, target_height, surprised_frame, SURPRISED_STAGE1_FRAMES);
        
        // 宽度保持不变
        int current_width = 90;
        
        int y_offset = (110 - current_height) / 2;
        
        gui_rect_set_size((gui_rounded_rect_t *)hg_rect_leftEyeOuter, current_width, current_height);
        gui_rect_set_size((gui_rounded_rect_t *)hg_rect_rightEyeOuter, current_width, current_height);
        gui_rect_set_position((gui_rounded_rect_t *)hg_rect_leftEyeOuter, 123, 105 + y_offset);
        gui_rect_set_position((gui_rounded_rect_t *)hg_rect_rightEyeOuter, 265, 105 + y_offset);
        
        // 眉毛保持原位
        gui_arc_set_position(hg_arc_left, 168, 151);
        gui_arc_set_position(hg_arc_right, 309, 151);
        gui_arc_set_radius(hg_arc_left, 80);
        gui_arc_set_radius(hg_arc_right, 80);
        gui_arc_set_start_angle(hg_arc_left, 240.0f);
        gui_arc_set_end_angle(hg_arc_left, 300.0f);
        gui_arc_set_start_angle(hg_arc_right, 240.0f);
        gui_arc_set_end_angle(hg_arc_right, 300.0f);
        
        if (surprised_frame >= SURPRISED_STAGE1_FRAMES)
        {
            surprised_step = 1;
            surprised_frame = 0;
        }
    }
    else if (surprised_step == 1)
    {
        // 阶段2：继续睁大+抖动
        surprised_frame++;
        
        // 眼睛高度 120 → 135
        int stage1_height = 120;
        int target_height = 135;
        int current_height = lerp(stage1_height, target_height, surprised_frame, SURPRISED_STAGE2_FRAMES);
        
        // 宽度保持不变
        int current_width = 90;
        
        int y_offset = (110 - current_height) / 2;
        
        // 左右抖动效果（在动画快结束时停止抖动）
        int shake_offset = 0;
        if (surprised_frame < SURPRISED_STAGE2_FRAMES - 2)
        {
            // 使用帧数产生抖动效果
            shake_offset = (surprised_frame % 4 < 2) ? SURPRISED_SHAKE_AMPLITUDE : -SURPRISED_SHAKE_AMPLITUDE;
        }
        
        gui_rect_set_size((gui_rounded_rect_t *)hg_rect_leftEyeOuter, current_width, current_height);
        gui_rect_set_size((gui_rounded_rect_t *)hg_rect_rightEyeOuter, current_width, current_height);
        gui_rect_set_position((gui_rounded_rect_t *)hg_rect_leftEyeOuter, 123 + shake_offset, 105 + y_offset);
        gui_rect_set_position((gui_rounded_rect_t *)hg_rect_rightEyeOuter, 265 + shake_offset, 105 + y_offset);
        
        // 眉毛上扬（0 → -25 像素）
        int brow_offset = lerp(0, -25, surprised_frame, SURPRISED_STAGE2_FRAMES);
        
        // 眉毛也抖动
        gui_arc_set_position(hg_arc_left, 168 + shake_offset, 151 + brow_offset);
        gui_arc_set_position(hg_arc_right, 309 + shake_offset, 151 + brow_offset);
        
        // 眉毛弧度增大（半径 80 → 60）
        int current_radius = lerp(80, 60, surprised_frame, SURPRISED_STAGE2_FRAMES);
        gui_arc_set_radius(hg_arc_left, current_radius);
        gui_arc_set_radius(hg_arc_right, current_radius);
        gui_arc_set_start_angle(hg_arc_left, 240.0f);
        gui_arc_set_end_angle(hg_arc_left, 300.0f);
        gui_arc_set_start_angle(hg_arc_right, 240.0f);
        gui_arc_set_end_angle(hg_arc_right, 300.0f);
        
        if (surprised_frame >= SURPRISED_STAGE2_FRAMES)
        {
            surprised_step = 2;
            surprised_frame = 0;
        }
    }
    else if (surprised_step == 2)
    {
        // 阶段3：保持最大状态，等待触发缓慢眨眼
        int max_height = 135;
        int current_width = 90;
        int y_offset = (110 - max_height) / 2;
        
        gui_rect_set_size((gui_rounded_rect_t *)hg_rect_leftEyeOuter, current_width, max_height);
        gui_rect_set_size((gui_rounded_rect_t *)hg_rect_rightEyeOuter, current_width, max_height);
        gui_rect_set_position((gui_rounded_rect_t *)hg_rect_leftEyeOuter, 123, 105 + y_offset);
        gui_rect_set_position((gui_rounded_rect_t *)hg_rect_rightEyeOuter, 265, 105 + y_offset);
        
        // 眉毛保持最高位置
        gui_arc_set_position(hg_arc_left, 168, 126);
        gui_arc_set_position(hg_arc_right, 309, 126);
        gui_arc_set_radius(hg_arc_left, 60);
        gui_arc_set_radius(hg_arc_right, 60);
        gui_arc_set_start_angle(hg_arc_left, 240.0f);
        gui_arc_set_end_angle(hg_arc_left, 300.0f);
        gui_arc_set_start_angle(hg_arc_right, 240.0f);
        gui_arc_set_end_angle(hg_arc_right, 300.0f);
        
        // 冷却计数器递增
        surprised_blink_cooldown++;
        
        // 冷却时间到达后，随机触发缓慢眨眼
        if (surprised_blink_cooldown >= SURPRISED_BLINK_COOLDOWN_FRAMES && rand() % 100 < 30)
        {
            surprised_step = 3;
            surprised_frame = 0;
            surprised_blink_cooldown = 0;
        }
    }
    else if (surprised_step == 3)
    {
        // 阶段4：缓慢闭眼
        surprised_frame++;
        int max_height = 135;
        int blink_height = 15;
        int current_height = lerp(max_height, blink_height, surprised_frame, SURPRISED_BLINK_CLOSE_FRAMES);
        int current_width = 90;
        int y_offset = (110 - current_height) / 2;
        
        gui_rect_set_size((gui_rounded_rect_t *)hg_rect_leftEyeOuter, current_width, current_height);
        gui_rect_set_size((gui_rounded_rect_t *)hg_rect_rightEyeOuter, current_width, current_height);
        gui_rect_set_position((gui_rounded_rect_t *)hg_rect_leftEyeOuter, 123, 105 + y_offset);
        gui_rect_set_position((gui_rounded_rect_t *)hg_rect_rightEyeOuter, 265, 105 + y_offset);
        
        // 眉毛保持最高位置
        gui_arc_set_position(hg_arc_left, 168, 126);
        gui_arc_set_position(hg_arc_right, 309, 126);
        gui_arc_set_radius(hg_arc_left, 60);
        gui_arc_set_radius(hg_arc_right, 60);
        gui_arc_set_start_angle(hg_arc_left, 240.0f);
        gui_arc_set_end_angle(hg_arc_left, 300.0f);
        gui_arc_set_start_angle(hg_arc_right, 240.0f);
        gui_arc_set_end_angle(hg_arc_right, 300.0f);
        
        if (surprised_frame >= SURPRISED_BLINK_CLOSE_FRAMES)
        {
            surprised_step = 4;
            surprised_frame = 0;
        }
    }
    else if (surprised_step == 4)
    {
        // 阶段5：缓慢睁眼
        surprised_frame++;
        int blink_height = 15;
        int max_height = 135;
        int current_height = lerp(blink_height, max_height, surprised_frame, SURPRISED_BLINK_OPEN_FRAMES);
        int current_width = 90;
        int y_offset = (110 - current_height) / 2;
        
        gui_rect_set_size((gui_rounded_rect_t *)hg_rect_leftEyeOuter, current_width, current_height);
        gui_rect_set_size((gui_rounded_rect_t *)hg_rect_rightEyeOuter, current_width, current_height);
        gui_rect_set_position((gui_rounded_rect_t *)hg_rect_leftEyeOuter, 123, 105 + y_offset);
        gui_rect_set_position((gui_rounded_rect_t *)hg_rect_rightEyeOuter, 265, 105 + y_offset);
        
        // 眉毛保持最高位置
        gui_arc_set_position(hg_arc_left, 168, 126);
        gui_arc_set_position(hg_arc_right, 309, 126);
        gui_arc_set_radius(hg_arc_left, 60);
        gui_arc_set_radius(hg_arc_right, 60);
        gui_arc_set_start_angle(hg_arc_left, 240.0f);
        gui_arc_set_end_angle(hg_arc_left, 300.0f);
        gui_arc_set_start_angle(hg_arc_right, 240.0f);
        gui_arc_set_end_angle(hg_arc_right, 300.0f);
        
        if (surprised_frame >= SURPRISED_BLINK_OPEN_FRAMES)
        {
            surprised_step = 2;  // 回到保持状态
            surprised_frame = 0;
        }
    }
}

// 眼睛动画回调函数
void eye_animation_callback_impl(void)
{
    // 根据当前表情调用对应的动画函数
    switch (current_emotion)
    {
        case EMOTION_NORMAL:
            emotion_normal_animation();
            break;
            
        case EMOTION_HAPPY:
            emotion_happy_animation();
            break;
            
        case EMOTION_SAD:
            emotion_sad_animation();
            break;
            
        case EMOTION_SURPRISED:
            emotion_surprised_animation();
            break;
            
        default:
            break;
    }
}

// 表情按钮点击回调
void hg_rect_emotionButton_onClick(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    
    // 切换到下一个表情
    current_emotion = (current_emotion + 1) % EMOTION_MAX;
    target_emotion = current_emotion;
    
    // 重置所有动画状态
    blink_step = 0;
    blink_frame = 0;
    blink_cooldown = 0;
    happy_step = 0;
    happy_frame = 0;
    happy_blink_count = 0;
    sad_step = 0;
    sad_frame = 0;
    sad_blink_cooldown = 0;
    surprised_step = 0;
    surprised_frame = 0;
    surprised_blink_cooldown = 0;
    
    // 更新标签文本
    gui_text_content_set((gui_text_t *)hg_label_emotionLabel, 
                         (void *)emotion_names[target_emotion], 
                         strlen(emotion_names[target_emotion]));
    

}
