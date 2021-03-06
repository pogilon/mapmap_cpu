/**
 * Copyright (C) 2017, Daniel Thuerck
 * TU Darmstadt - Graphics, Capture and Massively Parallel Computing
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD license. See the LICENSE file for details.
 */

#include "header/instance_factory.h"

#include "header/optimistic_tree_sampler.h"
#include "header/lock_free_tree_sampler.h"

NS_MAPMAP_BEGIN

template<typename COSTTYPE, bool ACYCLIC>
std::unique_ptr<TreeSampler<COSTTYPE, ACYCLIC>>
InstanceFactory<COSTTYPE, ACYCLIC>::
get_sampler_instance(
    const TREE_SAMPLER_ALGORITHM& alg,
    Graph<COSTTYPE> * graph)
{
    if(alg == OPTIMISTIC_TREE_SAMPLER)
    {
        return std::unique_ptr<TreeSampler<COSTTYPE, ACYCLIC>>(
            new OptimisticTreeSampler<COSTTYPE, ACYCLIC>(graph));
    }

    if(alg == LOCK_FREE_TREE_SAMPLER)
    {
        return std::unique_ptr<TreeSampler<COSTTYPE, ACYCLIC>>(
            new LockFreeTreeSampler<COSTTYPE, ACYCLIC>(graph));
    }

    return std::unique_ptr<TreeSampler<COSTTYPE, ACYCLIC>>(nullptr);
}

NS_MAPMAP_END