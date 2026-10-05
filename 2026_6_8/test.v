module mux4 (
    input  [1:0] sel,      // 选择信号
    input  [3:0] d,        // 4路输入，d[0]~d[3]
    output reg  y          // 单路输出
);
always @(*)begin
    case (sel)
        2'b00: y = d[0];
        2'b01: y = d[1];
        2'b10: y = d[2];
        2'b11: y = d[3];
        default: y = 1'b0;
    endcase
end
endmodule


module dff_sync_en (
    input       clk,      // 时钟
    input       rst_n,    // 异步复位，低电平有效
    input       en,       // 同步使能（高电平有效）
    input       d,        // 数据输入
    output reg  q         // 数据输出
);
always@(posedge clk or negedge rst_n)begin
    if(!rst_n) q<=0;
    else if(en )q<=d;
    else q<=q;
end
endmodule


module shift_reg_4bit (
    input           clk,      // 时钟
    input           rst_n,    // 异步复位，低电平有效
    input           dir,      // 方向控制：1=左移，0=右移
    input           sin,      // 串行输入（移入的数据）
    output reg [3:0] q        // 4位数据输出
);
always@(posedge clk or negedge rst_n)begin
    if(!rst_n)q<=4'b0000;
    else if(dir==1)q<={q[2:0],sin};
    else if(dir==0)q<={sin,q[3:1]};
    else q<=q;
end
endmodule

module seq_det_101 (
    input       clk,      // 时钟
    input       rst_n,    // 异步复位，低电平有效
    input       din,      // 串行输入，每个时钟周期1位
    output reg  dout      // 检测到 "101" 时输出1，否则0
);
reg [2:0] state=3'b000;
always@(posedge clk or negedge rst_n)begin
    if(!rst_n) begin
        dout<=0;
        state<=3'b000;
    end
    else begin
        if(state==3'b101)dout<=1;
        else dout<=0;
        state<={state[1:0],din};
    end
end
endmodule

module edge_detect (
    input       clk,
    input       rst_n,
    input       sig,        // 待检测信号
    output reg  rise,       // 上升沿标志（1个时钟周期脉冲）
    output reg  fall        // 下降沿标志（1个时钟周期脉冲）
);
reg last_sig=0;
always@(posedge clk or negedge rst_n)begin
    if(!rst_n)begin
        last_sig<=0;
        rise<=0;
        fall<=0;
    end
    else begin
        if(sig!=last_sig && sig==1)begin
            rise<=1;
            fall<=0;
        end
        else if(sig!=last_sig && sig==0)begin 
            fall<=1;
            rise<=0;
        end
        else begin
            rise<=0;
            fall<=0;
        end
        last_sig<=sig;
    end
end
endmodule 


module debounce (
    input       clk,        // 1kHz 时钟（慢时钟方便计数）
    input       rst_n,
    input       key_in,     // 原始按键输入（高电平表示按下）
    output reg  key_out     // 消抖后输出
);
reg [19:0] count=0;
always@(posedge clk or negedge rst_n)begin
    if(!rst_n)begin
        count<=0;
        key_out<=0;
    end
    else begin
        count<={count[18:0],key_in};
        if(count==20'hfffff)key_out<=1;
        else if(count==20'h00000)key_out<=0;
        else key_out<=key_out;
    end
end
endmodule