#include <iostream>
#include <vector>
#include <cmath>

/**
 * Simple demonstration of numerical methods for Euler equations
 * This is a basic example showing the mathematical concepts
 * discussed in the Quarto documentation.
 */

namespace euler_methods {
    
    // Basic 1D Euler state vector: [density, momentum, energy]
    struct EulerState {
        double rho;   // density
        double rho_u; // momentum
        double E;     // total energy
        
        EulerState(double density = 1.0, double velocity = 0.0, double pressure = 1.0) 
            : rho(density), rho_u(density * velocity) {
            // E = rho * (e + 0.5 * u^2), where e = p / ((gamma-1) * rho)
            const double gamma = 1.4;
            E = pressure / (gamma - 1.0) + 0.5 * rho * velocity * velocity;
        }
        
        double velocity() const { return rho_u / rho; }
        double pressure() const {
            const double gamma = 1.4;
            return (gamma - 1.0) * (E - 0.5 * rho_u * rho_u / rho);
        }
    };
    
    // Flux function F(U) for 1D Euler equations
    EulerState flux(const EulerState& U) {
        double u = U.velocity();
        double p = U.pressure();
        
        return EulerState{
            U.rho_u,                    // mass flux
            U.rho_u * u + p,           // momentum flux  
            u * (U.E + p)              // energy flux
        };
    }
    
    // Simple Rusanov (Lax-Friedrichs) numerical flux
    EulerState rusanov_flux(const EulerState& UL, const EulerState& UR) {
        auto FL = flux(UL);
        auto FR = flux(UR);
        
        // Simplified wave speed estimate
        double gamma = 1.4;
        double cL = std::sqrt(gamma * UL.pressure() / UL.rho);
        double cR = std::sqrt(gamma * UR.pressure() / UR.rho);
        double lambda = std::max(std::abs(UL.velocity()) + cL, std::abs(UR.velocity()) + cR);
        
        return EulerState{
            0.5 * (FL.rho + FR.rho) - 0.5 * lambda * (UR.rho - UL.rho),
            0.5 * (FL.rho_u + FR.rho_u) - 0.5 * lambda * (UR.rho_u - UL.rho_u),
            0.5 * (FL.E + FR.E) - 0.5 * lambda * (UR.E - UL.E)
        };
    }
}

int main() {
    using namespace euler_methods;
    
    std::cout << "=== Euler Methods Demonstration ===" << std::endl;
    std::cout << "Showcasing basic numerical methods for hyperbolic conservation laws" << std::endl;
    std::cout << std::endl;
    
    // Create example states for a shock tube problem
    EulerState left_state(1.0, 0.0, 1.0);   // rho=1, u=0, p=1
    EulerState right_state(0.125, 0.0, 0.1); // rho=0.125, u=0, p=0.1
    
    std::cout << "Left state:  rho=" << left_state.rho 
              << ", u=" << left_state.velocity() 
              << ", p=" << left_state.pressure() << std::endl;
              
    std::cout << "Right state: rho=" << right_state.rho 
              << ", u=" << right_state.velocity() 
              << ", p=" << right_state.pressure() << std::endl;
    
    // Compute Rusanov flux at interface
    auto interface_flux = rusanov_flux(left_state, right_state);
    
    std::cout << std::endl;
    std::cout << "Rusanov flux: rho_flux=" << interface_flux.rho 
              << ", momentum_flux=" << interface_flux.rho_u 
              << ", energy_flux=" << interface_flux.E << std::endl;
    
    std::cout << std::endl;
    std::cout << "This demonstrates the numerical methods documented in the Quarto projects." << std::endl;
    std::cout << "For complete mathematical analysis, see the portfolio documentation." << std::endl;
    
    return 0;
}