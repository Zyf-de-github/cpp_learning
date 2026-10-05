`timescale 1ns/1ns
module gray_code_counter(
    input            clk,
    input            rst_n,
    input            en,
    input            dir,       // 0=加(向上), 1=减(向下)
    input            load,
    input      [3:0] load_bin,
    output reg [3:0] gray,      // 当前 bin 的格雷码
    output reg [3:0] bin,       // 当前二进制状态
    output reg       wrap       // 回绕脉冲
);

    // 在此实现你的逻辑
    // 优先级：load > en；gray = bin ^ (bin >> 1)
always@(posedge clk or negedge rst_n)begin
    if(!rst_n)begin
        bin<=4'b0000;
        gray<=4'b0000;
        wrap<=1'b0;
    end
    else if(load==1)begin
        bin=load_bin;
        gray<=bin^(bin>>1);
        wrap<=1'b0;
    end
    else if(en==1 && dir==0)begin
        if(bin==15)begin
            wrap<=1;
        end
        else begin
            wrap<=0;
        end
        bin=bin+1;
        gray<=bin^(bin>>1);
    end
    else if(en==1 && dir==1)begin
        if(bin==0)begin
            wrap<=1;
        end
        else begin
            wrap<=0;
        end
        bin=bin-1;
        gray<=bin^(bin>>1);
    end
    else begin
        bin<=bin;
        gray<=bin^(bin>>1);
        wrap<=0;
    end
end

endmodule