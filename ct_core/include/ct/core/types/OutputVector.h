/**********************************************************************************************************************
This file is part of the Control Toolbox (https://github.com/ethz-adrl/control-toolbox), copyright by ETH Zurich.
Licensed under the BSD-2 license (see LICENSE file in main directory)
**********************************************************************************************************************/

#pragma once

namespace ct {
namespace core {

template <size_t OUTPUT_DIM, class SCALAR = double>
class OutputVector : public Eigen::Matrix<SCALAR, OUTPUT_DIM, 1>
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    typedef Eigen::Matrix<SCALAR, OUTPUT_DIM, 1> Base;
    static const size_t DIM = OUTPUT_DIM;

    OutputVector() {}
    virtual ~OutputVector() {}
    //! This constructor allows you to construct MyVectorType from Eigen expressions
    template <typename OtherDerived>
    OutputVector(const Eigen::MatrixBase<OtherDerived>& other) : Base(other)
    {
    }

    //! This method allows you to assign Eigen expressions to MyVectorType
    template <typename OtherDerived>
    OutputVector& operator=(const Eigen::MatrixBase<OtherDerived>& other)
    {
        this->Base::operator=(other);
        return *this;
    }

    //! get underlying Eigen type
    Base& toImplementation() { return *this; }
    //! get const underlying Eigen type
    const Base& toImplementation() const { return *this; }
};

} /* namespace core */
} /* namespace ct */
