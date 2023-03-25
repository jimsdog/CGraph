/***************************
@Author: Chunel
@Contact: chunel@foxmail.com
@File: GSchedule.h
@Time: 2023/3/25 19:01
@Desc: 
***************************/

#ifndef CGRAPH_GSCHEDULE_H
#define CGRAPH_GSCHEDULE_H

#include "../../GraphObject.h"
#include "GScheduleDefine.h"

CGRAPH_NAMESPACE_BEGIN

class GSchedule : public GraphObject {
protected:
    /**
     * 设置线程池内容
     * @param tp
     * @return
     */
    GSchedule* setSharedThreadPool(UThreadPoolPtr tp);

    CStatus init() override;

    CStatus run() override;

    CStatus destroy() override;

private:
    UThreadPoolPtr thread_pool_ = nullptr;          // 线程池类
    UThreadPoolConfig config_;                      // 线程池的配置信息
    GScheduleType type_ = GScheduleType::UNIQUE;    // 调度类型

    friend class GPipeline;
};

CGRAPH_NAMESPACE_END

#endif //CGRAPH_GSCHEDULE_H